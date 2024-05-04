#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ptr;
	char		*res;
	char		*tmp;
	char		buff[BUFFER_SIZE];
	char		*str;
	int		count_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (save)
		{
			ptr = ft_strchr(save, '\n');
			if (ptr)
			{
				res = ft_substr(save, 0, ptr - save + 1);
				tmp = ft_strdup(++ptr);
				save = ft_strdup(tmp);
				free(tmp);
				tmp = NULL;
				return (res);
			}
		}
		count_read = read(fd, buff, BUFFER_SIZE);
		if (count_read < 0)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		if (!count_read)
		{
			if (save && *save != '\0')
			{
				res = ft_strdup(save); 	
				free(save);
				save = NULL;
		        	return (res);
			}
			return (NULL);
		}
		if (!save)
			save = ft_cpybuff(buff, count_read);
		else
		{
			str = ft_cpybuff(buff, count_read);
			tmp = ft_strjoin(save, str);
			free(str);
			str = NULL;
			free(save);
			save = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
		}
		ptr = ft_strchr(save, '\n');
		if (ptr)
		{
			res = ft_substr(save, 0, ptr - save + 1);
			tmp = ft_strdup(++ptr);
			free(save);
			save = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
			if (*save == '\0')
			{
				free(save);
				save = NULL;
			}
			return (res);
		}
	}
}
