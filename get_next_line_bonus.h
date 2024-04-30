/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:20:28 by aconti            #+#    #+#             */
/*   Updated: 2023/12/13 15:24:54 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*find_line(char *str, int fd, int bytes_read);
char	*getstr(char *str);
int		len_to_newline(char *str);
char	*my_strjoin(char *s1, char *s2, int bytes_read);
void	*ft_calloc(size_t n, size_t size);
char	*final_function(char *str);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);

#endif