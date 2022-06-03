/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:46:56 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/03 13:57:34 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

char	*malloc_null(int i)
{
	char	*mall;

	mall = malloc(sizeof(char) * (i + 1));
	if (!mall)
		return (NULL);
	mall[0] = '\0';
	return (mall);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*mall;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	if (!s1)
	{
		s1 = malloc_null(0);
	}
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	mall = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (mall == NULL)
		return (NULL);
	while (i++ < size_s1)
		mall[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < size_s2)
		mall[size_s1 + i - 1] = s2[i - 1];
	mall[size_s1 + i - 1] = '\0';
	free(s1);
	return (mall);
}
