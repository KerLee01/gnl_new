#include "get_next_line_bonus.h"

char *join_line(t_list *node, int length)
{
	int i;
	char *joined_str;
	char *current_str;

	i = 0;
	joined_str = malloc(sizeof(*joined_str) * (length + 1));
	if(joined_str == NULL)
		return (free_nodes(node), NULL);
	while(node != NULL)
	{
		current_str = node->content;
		while(*current_str != '\0')
		{
			joined_str[i] = *current_str;
			i++;
			if(*current_str == '\n')
				break;
			current_str++;
		}
		node = node->next;
	}
	joined_str[i] = '\0';
	if(joined_str[0] == '\0')
		return (free(joined_str), NULL);
	return joined_str;
}

t_list *read_more(int fd, t_list *node, int *length)
{
	int byte;
	char *buffer;
	t_list* start;

	if(node == NULL)
		return NULL;
	start = node;
	while(ft_strchr(node->content, '\n') == NULL)
	{
		buffer = malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
		if(buffer == NULL)
			return NULL;
		byte = read(fd, buffer, BUFFER_SIZE);
		if(byte == -1)
			return (free(buffer), free_nodes(start), NULL);
		if(byte == 0)
			return (free(buffer), start);
		buffer[byte] = '\0';
		node = attach_node(byte, buffer, node, length);
	}
	return start;
}

char *updated_content(char *old_content)
{
	int i;
	int j;
	char *updated;

	i = 0;
	j = 0;
	while(old_content[j] != '\n')
		j++;
	if(old_content[j] == '\n')
		j++;
	updated = malloc(sizeof(*updated_content) * (ft_strlen(old_content) - j + 1));
	while(old_content[j] != '\0')
	{
		updated[i] = old_content[j];
		j++;
		i++;
	}
	updated[i] = '\0';
	return updated;
}

t_list *update_library(t_list *list)
{
	t_list *buffer;
	char *str;
	char *updated;

	while(list->next != NULL)
	{
		buffer = list;
		free(list->content);
		list = list->next;
		free(buffer);
	}
	str = list->content;
	if(ft_strchr(str, '\n') != NULL)
	{
		updated = updated_content(str);
		free(list->content);
		list->content = updated;
		return list;
	}
	free(list->content);
	free(list);
	return NULL;
}

char *get_next_line(int fd)
{
	static t_list *library_fd[4096];
	char *line;
	int str_length;

	str_length = 0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if(library_fd[fd] == NULL)
		library_fd[fd] = create_new_node(strdup(""));
	if(library_fd[fd] == NULL)
		return NULL;
	str_length += ft_strlen(library_fd[fd]->content);
	library_fd[fd] = read_more(fd, library_fd[fd], &str_length);
	if(library_fd[fd] == NULL)
		return NULL;
	line = join_line(library_fd[fd], str_length);
	library_fd[fd] = update_library(library_fd[fd]);
	return line;
}
