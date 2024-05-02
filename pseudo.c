if (save)
	if (nl in save)
		save is cut
		return nl

count_read = read(fd, buf, bufsiz)
	if count_read < 0
		return NULL
	if count_read == 0
		if (nl in save)
			save is cut;
			return nl;
		else
			return save;

while ( i < count_read)
	str[i] = buf[i]
str[count_read] = '\0';

if (!save)
	save = strdup(str);
else
	save = strjoin(save, str);












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
	while (!(res = ft_return_if_nl(&save)))
	{
		count_read = ft_read_fd(buff, fd);
		if (count_read < 0)
			return (NULL);
		else if (count_read && count_read <= BUFFER_SIZE)
		{
			str = malloc(sizeof(char) * (count_read + 1));
			str[count_read] = '\0';
			ft_strncpy(str, buff, count_read);
		}
		if (!save)
			save = ft_strdup(str);
		else
		{
			tmp = ft_strjoin(save, str);
			free(save);
			save = ft_strdup(tmp);
			free(tmp);
		}
	}
	return (res);
}
