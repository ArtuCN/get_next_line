/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:19:01 by aconti            #+#    #+#             */
/*   Updated: 2024/01/29 19:41:01 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_substr(char *s, int start, int len)
{
	char	*sb;
	int		i;

	if ((int)start >= ft_strlen(s))
	{
		sb = malloc(sizeof(char) * 1);
		if (sb == NULL)
			return (NULL);
		*sb = '\0';
		return (sb);
	}
	s += start;
	if (ft_strlen(s) <= (int)len)
		sb = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		sb = malloc(sizeof(char) * (len + 1));
	if (sb == 0)
		return (0);
	i = -1;
	while (s[++i] && i < len)
		sb[i] = s[i];
	sb[i] = '\0';
	return (sb);
}

char	*find_line(char *str, int fd, int bytes_read)
{
	char	*buffer;
	char	*temp;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str || !buffer)
		return (NULL);
	while (!(ft_strchr(buffer, '\n') && ft_strchr(buffer, '\0'))
		&& bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		temp = str;
		buffer[bytes_read] = '\0';
		str = my_strjoin(temp, buffer, bytes_read);
		free(temp);
	}
	free(buffer);
	return (str);
}

char	*final_function(char *str)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	len = ft_strlen(str);
	len -= i;
	temp = str;
	str = ft_substr(temp, i, len + 1);
	free(temp);
	return (str);
}

char	*getstr(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str && str[i] != 0 && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		new[i + 1] = 0;
	}
	else
		new[i] = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*char_left[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
	{
		if (char_left[fd])
			free(char_left[fd]);
		char_left[fd] = NULL;
		return (NULL);
	}
	char_left[fd] = find_line(char_left[fd], fd, 1);
	if (!char_left[fd])
		return (NULL);
	result = getstr(char_left[fd]);
	char_left[fd] = final_function(char_left[fd]);
	if (!*result)
	{
		free(char_left[fd]);
		char_left[fd] = NULL;
		free(result);
		return (NULL);
	}
	return (result);
}
// int main ()
// {
// 	char *str;

// 	int	fd;
// 	fd = open("fd7.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd8.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd9.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd10.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd11.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd12.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);
// 	fd = open("fd14.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("fd13.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("\n %s", str);
// 	free(str);
// 	close(fd);

// 	return (0);
// }
