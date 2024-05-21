/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:17 by afocant           #+#    #+#             */
/*   Updated: 2024/05/21 15:00:15 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_and_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char) c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *) s);
}

char	*ft_duplicate_str(const char *s1, char c)
{
	size_t	len;
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len] != c)
		len++;
	if (c != '\0')
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != c)
	{
		s2[i] = s1[i];
		i++;
	}
	if (c != '\0')
		s2[i++] = c;
	s2[i] = '\0';
	return (s2);
}

char	*ft_cut_stash(char *stash, char *start)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(start);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (ft_free_and_null(&stash));
	i = 0;
	while (i < len)
		res[i++] = *start++;
	res[i] = '\0';
	if (!*res)
		ft_free_and_null(&res);
	ft_free_and_null(&stash);
	return (res);
}
