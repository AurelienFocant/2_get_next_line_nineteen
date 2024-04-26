#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

int		ft_getlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_return_if_nl(char *str)
{
	char	*ptr;
	char	*res;
	char	*tmp;

	if (str)
	{
		if ((ptr = ft_strchr(str, '\n')))
		{
				res = ft_substr(str, 0, ft_getlen(str, '\n'));
				tmp = ft_strdup(++ptr);
				free(str);
				str = ft_strdup(tmp); 
				free(tmp);
				return (res);
		}
	}
	return (NULL);
}

int	ft_read_fd(char *buff, int fd)
{
	int			count_read;
	
	if ((count_read = (read(fd, buff, BUFFER_SIZE - 1))) < 0)
	{
		printf("error");
		return (-1);
	}
	else if (count_read == 0)
	{
		printf("EOF");
		return (0);
	}
	else
		buff[count_read] = '\0';	
	return (count_read);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;
	char		*tmp;
	char		buff[BUFFER_SIZE];

	while (!(res = ft_return_if_nl(save)))
	{
		if (ft_read_fd(buff, fd) <= 0)
			return (NULL);
		if (!save)
			save = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(save, buff);
			free(save);
			save = ft_strdup(tmp);
			free(tmp);
		}
	}	
	return (res);
}
