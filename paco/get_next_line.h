/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:03:38 by afocant           #+#    #+#             */
/*   Updated: 2024/05/21 16:12:32 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/resource.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char **stash);
char	*ft_join_stash_buff(char *stash, char *buf, size_t buf_len);
char	*ft_divide_stash(char **stash);

char	*ft_free_and_null(char **str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_extract_line(char *stash);
char	*ft_trim_stash(char *stash, char *start);

#endif
