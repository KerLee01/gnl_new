#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
   char *content;
   struct s_list *next;
} t_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

t_list *create_new_node(char *content);
t_list *attach_node(int byte, char *buffer, t_list *node, int *length);
char *get_next_line(int fd);
void free_nodes(t_list *current);
void add_node(t_list *current, t_list *new);
int count_join_length(t_list *node);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
#endif
