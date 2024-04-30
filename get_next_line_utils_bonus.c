/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:18 by aconti            #+#    #+#             */
/*   Updated: 2023/12/13 15:23:46 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i] != (unsigned char)c && s[i])
		i++;
	if ((char)s[i] == ((unsigned char)c))
		return ((char *)s + i);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2, int bytes_read)
{
	char	*r;
	int		i;
	int		j;

	r = 0;
	i = 0;
	j = 0;
	r = (char *)malloc(bytes_read + ft_strlen(s1) + 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size * n)
		((char *)ptr)[i++] = 0;
	return (ptr);
}
