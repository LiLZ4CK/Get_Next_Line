/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:43:39 by zwalad            #+#    #+#             */
/*   Updated: 2021/12/03 17:43:55 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include    <stdlib.h>
# include    <stdio.h>
# include    <unistd.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

int		ft_strchr(char *str);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*get_next(char *str);
char	*get_line(char *str);
char	*norm_kekw(char *str, int fd);

#endif