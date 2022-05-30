/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:31 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/30 23:44:35 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>


/*char *get_next_line(int fd)
{


}*/

int	main(void)
{
	int		fd;
	size_t	read_len;
	char	*data;
	size_t	i;
		
	i = 0;
	read_len = 0;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_len = read(fd, data, BUFFER_SIZE);
	if(read_len < 0)
		return (0);
	while (i < read_len)
	{
		printf("%c", data[i]);
		i++;
	}
	
	printf("\nfd = %d\n", fd);
	printf("%d", BUFFER_SIZE);
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
