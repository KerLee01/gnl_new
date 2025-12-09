/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:21:03 by kerlee            #+#    #+#             */
/*   Updated: 2025/12/09 17:36:38 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

t_list				*create_new_node(char *content);
t_list				*attach_node(int byte, char *buffer, t_list *node,
						int *length);
char				*get_next_line(int fd);
void				free_nodes(t_list *current);
void				add_node(t_list *current, t_list *new);
int					count_join_length(t_list *node);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
#endif
