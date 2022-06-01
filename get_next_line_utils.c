/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:46:56 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/01 20:27:39 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


//de momento no la uso
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mall;
	size_t	count;
	size_t	len_src;

	len_src = ft_strlen(s);
	count = 0;
	if (len_src < start)
		mall = (char *)malloc(sizeof(char) * 1);
	else if (len_src - start < len)
		mall = malloc(sizeof(char) * (len_src - start + 1));
	else
		mall = (char *)malloc(sizeof(char) * (len + 1));
	if (!mall)
		return (NULL);
	while (start + count < len_src && count < len)
	{
		mall[count] = s[start + count];
		count++;
	}
	mall[count] = '\0';
	return (mall);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*mall;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if ((ft_strlen(s1) + ft_strlen(s2)) == 0)
		mall = (char *)malloc(sizeof(char) * 1);
	else
		mall = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mall == NULL)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i] != '\0')
	{
		mall[i] = s1[i];
		i++;
	}
	while ((i + j) < (ft_strlen(s1) + ft_strlen(s2) + 1)
		&& s2[j] != '\0')
	{
		mall[i + j] = s2[j];
		j++;
	}
	mall[i + j] = '\0';
	return (mall);
}

char	*malloc_null(int i)
{
	char	*mall;

	mall = malloc(sizeof(char) * (i + 1));
	if(!mall)
		return (NULL);
	mall[BUFFER_SIZE] = '\0';
	return (mall);
}
