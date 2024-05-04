/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:17 by afocant           #+#    #+#             */
/*   Updated: 2024/04/29 16:34:13 by afocant          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!len || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s[start] && len--)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		i;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*joined;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (total_len + 1));
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

int	ft_getlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
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
