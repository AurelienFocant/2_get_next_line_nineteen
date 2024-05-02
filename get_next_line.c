#include <stdio.h>

#include "get_next_line.h"

int	ft_getlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_return_if_nl(char **str)
{
	char	*ptr;
	char	*res;
	char	*tmp;

	if (*str)
	{
		if ((ptr = ft_strchr(*str, '\n')))
		{
			res = ft_substr(*str, 0, ft_getlen(*str, '\n'));
			tmp = ft_strdup(++ptr);
			free(*str);
			*str = ft_strdup(tmp);
			free(tmp);
			return (res);
		}
	}
	return (NULL);
}

int	ft_read_fd(char *buff, int fd)
{
	int	count_read;

	count_read = read(fd, buff, BUFFER_SIZE); 
	if (count_read < 0)
		return (-1);
	else
		return (count_read);
}

char	*ft_cpybuff(char *buf, int count)
{
	int		i;
	char	*str;

	str = malloc((count + 1) * sizeof(char));
	i = 0;
	while (i < count)
	{
		str[i] = buf[i];
		i++;
	}	
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;
	char		*tmp;
	char		buff[BUFFER_SIZE];
	int			count_read;
	char		*str;

	if (BUFFER_SIZE < 1)
		return (NULL);
	while(1)
	{
		if (save)
		{
			res = ft_return_if_nl(&save);
			if (res)
				return (res);
		}
		count_read = read(fd, buff, BUFFER_SIZE); 
		if (count_read < 0)
			return (NULL);
		if (!count_read)
		{
			if (save)
			{
				res = ft_return_if_nl(&save);
				if (res)
					return (res);
			}
			else
			{
				if (save)
				{
					res = ft_strdup(save);
					save = NULL;
					free(save);
					return (res);
				}
				else
					return (NULL);
			}
		}
		if (!save)
			save = ft_cpybuff(buff, count_read);
		else
		{
			str = ft_cpybuff(buff, count_read);
			tmp = ft_strjoin(save, str);
			free(save);
			save = ft_strdup(tmp);
			free(tmp);
			free(str);
		}
	}
}
