#include "CircularBuffer.h"

int 				create_elem_in_buffer(CircularBuffer *cb, char c)
{
	CircularBuffer	*node;

	if ((node = malloc(sizeof(CircularBuffer))) == NULL)
		return (FALSE);
	node->c = c;
	node->next = cb->next;
	node->head = cb->head;
	cb->next = node;
	return (TRUE);
}

int					create_circular_buffer(CircularBuffer **cb)
{
	CircularBuffer 	*tmp;
	int				i;

	i = 0;
	(*cb)->c = BUFFER_CHAR;
	(*cb)->head = (*cb);
	(*cb)->next = (*cb);
	tmp = (*cb);
	while (i < BUFFER_SIZE - 1)
	{
		create_elem_in_buffer(tmp, BUFFER_CHAR);
		tmp = tmp->next;
		i++;
	}
	printf("---- SUCCESS CREATING CIRCULAR BUFFER ------\n");
	return (TRUE);
}

int					add_str_in_buffer(CircularBuffer **cb, char *str)
{
	CircularBuffer 	*tmp;
	int				i;

	i = 0;
	tmp = (*cb);
	while (str[i] != 0)
	{
		tmp->c = str[i];
		tmp = tmp->next;
		i++;
	}
	*(cb) = tmp;
	if (str[i - 1] == '\n')
		return (TRUE);
	return (FALSE);
}

void 				reset_elem_in_buffer(CircularBuffer **cb, int nb_char)
{
	CircularBuffer 	*tmp;
	int 			i;

	i = 0;
	tmp = (*cb)->head;
	while (i < nb_char)
	{
		printf("DELETE LOOP %c\n", tmp->c);
		tmp->c = BUFFER_CHAR;
		++i;
		tmp = tmp->next;
	}
}

char 		*get_data_of_buffer(CircularBuffer *cb)
{
	char 	*str;
	int		i;

	i = 0;
	if ((str = malloc(sizeof(char) * 64)) == NULL)
		return (NULL);
	str = memset(str, 0, 64);
	cb = cb->head;
	if (cb->c != BUFFER_CHAR)
	{
		while (cb->c != '\n' && i < BUFFER_SIZE)
		{
			str[i] = cb->c;
			cb = cb->next;
			++i;
		}
		return (str);
	}
	free (str);
	return (NULL);
}

void  				display_circular_buffer(CircularBuffer *front_ptr, int mode)
{
	CircularBuffer  *it;

	int i;
	it = front_ptr->head;
	if (mode == 1)
	{
		for (i = 0; i < BUFFER_SIZE; i++)
		{
			printf("current = %p && next = %p && head = %p && c = %d\n", it, it->next, it->head, (it->c == 0) ? it->c + 48 : it->c);
			it = it->next;
		}

	}
	else
	{
		for (i = 0; it->c != BUFFER_CHAR && i < BUFFER_SIZE; i++)
		{
			printf("current = %p && next = %p && head = %p && c = %d\n", it, it->next, it->head, it->c);
			it = it->next;
		}
	}
}