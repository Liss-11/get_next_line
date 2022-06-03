/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:19:10 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/03 15:49:43 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
//para el read
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
//para el read
# include <unistd.h>
//para el size_t
# include <string.h>

char	*get_next_line(int fd);
char	*fd_read(int fd, char *data);
char	*take_line(char *data);
char	*clean_data(char *data);

//Funciones de utils
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*malloc_null(int i);

#endif

#if	BUFFER_SIZE
#endif
