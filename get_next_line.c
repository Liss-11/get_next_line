/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:31 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/01 20:27:42 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>


//Coje data, y le extra la primera linea, devolviendo un data limpio de la primera linea.
//queda el residuo
char *clean_data(char *data)
{

}

//coje data, y devuelve una linea que sera desde data 0 hasta '\n' INCLUIDO!! o final de data '\0'
char *take_line(char *data)
{
	int 	i;
	char	*line;

	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data[i] == '\n')
		line = ft_substr(data, 0, (i + 1));
	line = ft_substr(data, 0, i);
	return (line);
}

//Carga en data, hasta poner un \n o llegar al final '\0'
char	*fd_read(int fd, char *data)
{
	char	*str;
	int  	num_bites;
	//size_t	num_bites;

	str = malloc_null(BUFFER_SIZE);
	if (!str)
		return (NULL);
	num_bites = 1;
	while (num_bites > 0 && !ft_strchr(str, '\n'))
	{
		num_bites = read(fd, str, BUFFER_SIZE);
		if(num_bites > 0)
		{	
			//str[num_bites] = '\0';
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
	char static		*data = NULL;
	int				i;
	char 			*line;

	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	//Data vacio, o hay data (residuo), pero no contiene ningun salto de linea - entonces leemos mas
	if(!data || (data && !ft_strchr(data, '\n')))
		data = fd_read(fd, data);
	line = take_line(data);
	if(!line)
		return(NULL);
	data = clean_data(data);
	
	return (data);
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
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
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
