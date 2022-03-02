/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:41:13 by binam             #+#    #+#             */
/*   Updated: 2022/02/02 14:47:10 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *buf);
char	*get_next_line(int fd);
char	*get_new_line(char *buffer);
char	*get_line(int fd, char *buffer);
char	*strjoin(char *s1, char *s2);
char	*get_new_buffer(char *buffer);
int		find_nl_char(char *buffer);

#endif
