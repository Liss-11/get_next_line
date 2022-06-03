/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:31 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/03 14:14:11 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*clean_data(char *data)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	rest = ft_substr(data, (i + 1), (ft_strlen(data) - (i + 1)));
	free (data);
	return (rest);
}

char	*take_line(char *data)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!data[0])
		return (NULL);
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data[i] == '\n')
		line = ft_substr(data, 0, i + 1);
	else
		line = ft_substr(data, 0, i);
	return (line);
}

char	*fd_read(int fd, char *data)
{
	char	*str;
	int		num_bites;

	str = malloc_null(BUFFER_SIZE);
	if (!str)
		return (NULL);
	num_bites = 1;
	while (num_bites > 0 && !ft_strchr(str, '\n'))
	{
		num_bites = read(fd, str, BUFFER_SIZE);
		if (num_bites > 0)
		{	
			str[num_bites] = '\0';
			data = ft_strjoin(data, str);
		}
	}
	if (num_bites == -1)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (data);
}

char	*get_next_line(int fd)
{
	char static	*data;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if ((data && !(ft_strchr(data, '\n'))) || !data)
		data = fd_read(fd, data);
	if (!data)
		return (NULL);
	line = take_line(data);
	if (!line)
	{
		free(data);
		return (NULL);
	}
	data = clean_data(data);
	return (line);
}
