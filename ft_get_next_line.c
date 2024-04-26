#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

int		ft_getlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ptr;
	char		*res;
	char		*tmp;
	char		buff[BUFFER_SIZE];
	int			count_read;

	// if theres \n in save already
	
	
	if (save)
	{
		if ((ptr = ft_strchr(save, '\n')))
		{
				res = ft_substr(save, 0, ft_getlen(save, '\n'));
				tmp = ft_strdup(++ptr);
				free(save);	
				save = tmp; 
				free(tmp);
				return (res);
		}
	}

	while ((count_read = (read(fd, buff, BUFFER_SIZE -1))) != 0)
				printf("%i\n", count_read);
	if (count_read < 0)
		return (NULL);
	else
		buff[count_read] = '\0';	
	
	if ((ptr = ft_strchr(buff, '\n')))
	{
		if (!save)
			res = ft_substr(buff, 0, ft_getlen(buff, '\n'));
		else
		{
			res = ft_strjoin(save, ft_substr(buff, 0, ft_getlen(buff, '\n')));
			free(save);	
		}
		tmp = ft_strdup(++ptr);
		save = ft_strdup(tmp); 
		free(tmp);
		return (res);
	}

	

	return (res);
}
