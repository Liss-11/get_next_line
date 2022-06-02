/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:31 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/02 23:20:20 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>


//Coje data, y le extra la primera linea, devolviendo un data limpio de la primera linea.
//queda el residuo
char *clean_data(char *data)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data[i] == '\0')
		rest = malloc_null(1);
	rest = ft_substr(data, (i + 1), (ft_strlen(data) - i));
//	printf("In clean: %s\n", data);
	//printf("REST: %s", rest);
	return (rest);
}

//coje data, y devuelve una linea que sera desde data 0 hasta '\n' INCLUIDO!! o final de data '\0'
char *take_line(char *data)
{
	size_t	i;
	char	*line;

	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data[i] == '\n')
		line = ft_substr(data, 0, i + 1);
	else
		line = ft_substr(data, 0, i);
	return (line);
}

//Carga en data, hasta poner un \n o llegar al final '\0'
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
		if(num_bites > 0)
		{	
			if (!data)
			{
				data = malloc_null(1);
				data = ft_strjoin(data, str);
			}
			else
				data = ft_strjoin(data, str);
		}
	}
	if(num_bites == -1)
	{
		free(str);
		free(data);
		return(NULL);
	}
	free(str);
	return(data);
}

char *get_next_line(int fd)
{
	char static		*data;
	char 			*line;

//	printf("Data before_read: %s\n", data);
	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	//Data vacio, o hay data (residuo), pero no contiene ningun salto de linea - entonces leemos mas
	if ((data && !(ft_strchr(data, '\n'))) || !data)
	{
		data = fd_read(fd, data);
//		printf("Data read: %s\n", data);
	}
/*	if (!data)
	{
		data = fd_read(fd, data);
		printf("Data read_first: %s\n", data);
	}
	else if (data != NULL && !ft_strchr(data, '\n'))
	{
		data = fd_read(fd, data);
		printf("Data read_consecutive: %s\n", data);
	}*/
	line = take_line(data);
	if(!line)
		return(NULL);
//	printf("In get_next_lin: %s\n", data);
	data = clean_data(data);
//	printf("DATA: %s\n", data);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	int 	i;

	i = 0;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("In main: %s", line);
		i++;
	}
	close(fd);
	return (0);
}

/* - falta iterar el BUFFER_SIZE, hasta que se enentra un salto de linea, y guardar en el malloc 
la linia hasta el salto (incluido). Debo detectar el salto de linea para dejar de iterar
 - el resto de caracteres que me he pasado, los debo guarda en una variableo static, para que al llamar la funcion de nuevo, esten alli.
  - si mi variable no es vacia, los caracteres que tiene guardados se concatenaran al inicio del nuevo malloc, que leer'a hasta el salto de linea.
  - mi funcion devuelve el numero de linas que se me piden en el main.
  - si el BUFFER_SIZE es 0, tengo que mandar error
  - controlar los leaks!!
*/
