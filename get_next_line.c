/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:11:49 by afocant           #+#    #+#             */
/*   Updated: 2024/05/14 20:54:42 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_divide_save(char **save)
{
	char	*res;
	char	*tmp;
	char	*nl;

	if (!*save)
		return (NULL);
	nl = ft_strchr(*save, '\n');
	if (!nl)
		return (NULL);
	res = ft_duplicate_str(*save, '\n');
	tmp = ft_duplicate_str(++nl, '\0');
	if (*tmp)
	{
		free(*save);
		*save = tmp;
	}
	else
	{
		free(tmp);
		free(*save);
		*save = NULL;
	}
	tmp = NULL;
	return (res);
}

char	*ft_reached_eof(char **save)
{
	char		*res;

	res = NULL;
	if (ft_strchr(*save, '\n'))
		return (ft_divide_save(save));
	if (*save)
	{
		if (**save)
			res = ft_duplicate_str(*save, '\0');
		free(*save);
		*save = NULL;
		if (res)
			return (res);
	}
	return (NULL);
}

void	ft_join_save_str(char **save, char **str)
{
	char	*tmp;

	tmp = ft_joinstrs(*save, *str);
	free(*str);
	*str = NULL;
	if (!tmp)
	{
		free(*save);
		*save = NULL;
		return ;
	}
	if (*save)
		free(*save);
	*save = tmp;
	tmp = NULL;
}

char	*ft_read_into_buff(int fd, char **save)
{
	char		buff[BUFFER_SIZE];
	int			count_read;
	char		*str;

	count_read = read(fd, buff, BUFFER_SIZE);
	while (count_read)
	{
		str = ft_cpybuff(buff, count_read);
		if (!str || count_read < 0)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		ft_join_save_str(save, &str);
		if (ft_strchr(*save, '\n'))
			return (ft_divide_save(save));
		count_read = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_reached_eof(save));
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*res;
	struct rlimit	stacklim;

	if (getrlimit(RLIMIT_STACK, &stacklim) == 0)
		if ((long long unsigned) BUFFER_SIZE >= stacklim.rlim_cur)
			return (NULL);
	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	res = ft_divide_save(&save);
	if (res)
		return (res);
	res = ft_read_into_buff(fd, &save);
	if (res)
		return (res);
	return (NULL);
}
