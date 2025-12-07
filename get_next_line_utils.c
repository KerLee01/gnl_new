#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*str;

	str = (char *)s;
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc % 256)
			return (str);
		str++;
	}
	if (*str == '\0' && uc == '\0')
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

t_list *attach_node(int byte, char *buffer, t_list *node, int *length)
{
	t_list *new;

	new = create_new_node(buffer);
	if(new == NULL)
		return NULL;
	node->next = new;
	if(ft_strchr(buffer, '\n') == NULL)
		*length = *length + byte;
	else if(ft_strchr(buffer, '\n') != NULL)
	{
		while(*buffer && *buffer != '\n')
		{
			(*length)++;
			buffer++;
		}
		if(*buffer == '\n')
			(*length)++;
	}
	return new;
}

t_list *create_new_node(char *content)
{
	t_list *new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;

	new->content = content;
	new->next = NULL;

	return new;
}

void free_nodes(t_list *current)
{
	t_list *buffer;

	while(current->next != NULL)
	{
		free(current->content);
		buffer = current;
		current = current->next;
		free(buffer);
	}
	free(current->content);
	free(current);
}
