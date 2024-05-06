#include "get_next_line.h"

char	*ft_divide_save(char *save, char *nl)
{
	char	*res;
	char	*tmp;

	res = ft_substr(save, 0, nl - save + 1);
	tmp = ft_strdup(++nl);
	free(save);
	if (*tmp)
		save = ft_strdup(tmp);
	else
		save = NULL;
	free(tmp);
	tmp = NULL;
	return (res);
}

char	*ft_get_line_in_save(char *save)
{
	char	*nl;

	if (!save)
		return (NULL);
	nl = ft_strchr(save, '\n');
	if (nl)
		return (ft_divide_save(save, nl));
	else
		return (NULL);
}

char	*ft_read_into_buff(int fd, char *buff, char *save)
{
	int			count_read;
	char		*str;
	char		*tmp;
	char		*nl;
	char		*res;

	count_read = 1;
	while (count_read)
	{
		count_read = read(fd, buff, BUFFER_SIZE);
		if (count_read < 0)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		str = ft_cpybuff(buff, count_read);
		tmp = ft_joinstrs(save, str);
		save = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		nl = ft_strchr(save, '\n');
		if (nl)
			return (ft_divide_save(save, nl));
	}
	if (save && *save != '\0')
	{
		res = ft_strdup(save);
		free(save);
		save = NULL;
		return (res);
	}
	return (NULL);
}

char	*get_next_fkinline(int fd)
{
	static char	*save;
	char		*res;
	char		buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_get_line_in_save(save);
	if (res)
		return (res);
	res = ft_read_into_buff(fd, buff, save);
	if (res)
		return (res);
	return (NULL);
}
/*
*/
