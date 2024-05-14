/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:03:38 by afocant           #+#    #+#             */
/*   Updated: 2024/05/14 21:04:49 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/resource.h>

char	*get_next_line(int fd);
char	*ft_read_into_buff(int fd, char **save);
void	ft_join_save_str(char **save, char **str);
char	*ft_reached_eof(char **save);
char	*ft_divide_save(char **save);

char	*ft_cpybuff(char *buf, int count);
char	*ft_joinstrs(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_duplicate_str(const char *s1, char c);
size_t	ft_strlen(const char *s);

#endif
