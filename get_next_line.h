/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:19:10 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/30 23:44:38 by afrolova         ###   ########.fr       */
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



#endif

#if	BUFFER_SIZE
#endif
