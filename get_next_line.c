#include "get_next_line.h"

char	*ft_divide_save(char **save, char *nl)
{
	char	*res;
	char	*tmp;

	res = ft_substr(*save, 0, nl - *save + 1);
	tmp = ft_strdup(++nl);
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

char	*ft_get_line_in_save(char **save)
{
	char	*nl;

	if (!*save)
		return (NULL);
	nl = ft_strchr(*save, '\n');
	if (nl)
		return (ft_divide_save(save, nl));
	else
		return (NULL);
}

char	*ft_read_into_buff(int fd, char *buff, char **save)
{
	int			count_read;
	char		*str;
	char		*tmp;
	char		*nl;
	char		*res;

	res = NULL;
	count_read = read(fd, buff, BUFFER_SIZE);
	while (count_read)
	{
		if (count_read < 0)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		str = ft_cpybuff(buff, count_read);
		if (!str)
		{
			free(*save);
			return (NULL);
		}
		tmp = ft_joinstrs(*save, str);
		free(str);
		str = NULL;
		if (!tmp)
		{
			free(*save);
			return (NULL);
		}
		if (*save)
			free(*save);
		*save = tmp;
		tmp = NULL;
		if (!*save)
			return (NULL);
		nl = ft_strchr(*save, '\n');
		if (nl)
			return (ft_divide_save(save, nl));
		count_read = read(fd, buff, BUFFER_SIZE);
	}
	nl = ft_strchr(*save, '\n');
	if (nl)
		return (ft_divide_save(save, nl));
	if (*save)
	{
		if (**save)
			res = ft_strdup(*save);
		free(*save);
		*save = NULL;
		if (res)
			return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;
	char		buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	res = ft_get_line_in_save(&save);
	if (res)
		return (res);
	res = ft_read_into_buff(fd, buff, &save);
	if (res)
		return (res);
	return (NULL);
}
/*
*/
