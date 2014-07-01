#include "CircularBuffer.h"

int 				add_elem_in_buffer(CircularBuffer *cb, char c)
{
	CircularBuffer	*node;

	if ((node = malloc(sizeof(CircularBuffer *))) == NULL)
		return (FALSE);
	node->c = c;
	node->next = cb->next;
	node->head = cb->head;
	cb->next = node;
	cb = cb->next;
	return (TRUE);
}

int					create_circular_buffer(CircularBuffer *cb)
{
	CircularBuffer 	*tmp;
	int	i;

	i = 0;
	printf("---- CREATING CIRCULAR BUFFER ------\n");
	/*if ((cb = malloc(sizeof(CircularBuffer *))) == NULL)
		return (FALSE);*/
	cb->c = 48;
	cb->head = cb;
	cb->next = cb;
	tmp = cb;
	while (i < BUFFER_SIZE - 1)
	{
		add_elem_in_buffer(tmp, 48);
		i++;
	}
	printf("---- SUCCESS CREATING CIRCULAR BUFFER ------\n");
	return (TRUE);
}

int		add_str_in_buffer(CircularBuffer *cb, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		add_elem_in_buffer(cb, str[i]);
		i++;
	}
	if (str[i - 1] == '\n')
		return (TRUE);
	return (FALSE);
}

void  				display_circular_buffer(CircularBuffer *front_ptr)
{
	CircularBuffer  *it;

	int i;
	it = front_ptr;
	for (i = 0; it->c != 48; i++)
	{
    	printf("current = %p && next = %p && head = %p && c = %d\n", it, it->next, it->head, it->c);
    	it = it->next;
	}
}