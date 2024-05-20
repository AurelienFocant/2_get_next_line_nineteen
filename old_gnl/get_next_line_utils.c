/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:17 by afocant           #+#    #+#             */
/*   Updated: 2024/05/14 21:05:30 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char) c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *) s);
}

char	*ft_joinstrs(char *s1, char *s2)
{
	char	*joined;
	int		i;

	joined = NULL;
	if (!s1 || !s2)
	{
		if (!s1)
			joined = ft_duplicate_str(s2, '\0');
		else if (!s2)
			joined = ft_duplicate_str(s1, '\0');
		if (!joined)
			return (NULL);
		return (joined);
	}
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}

char	*ft_cpybuff(char *buf, int count)
{
	int		i;
	char	*str;

	if (!buf || count <= 0)
		return (NULL);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
