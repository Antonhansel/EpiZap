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
	int	i;

	i = 0;
	printf("---- CREATING CIRCULAR BUFFER ------\n");
	(*cb)->c = 48;
	(*cb)->head = (*cb);
	(*cb)->next = (*cb);
	tmp = (*cb);
	while (i < BUFFER_SIZE - 1)
	{
		create_elem_in_buffer(tmp, 48);
		tmp = tmp->next;
		i++;
	}
	printf("---- SUCCESS CREATING CIRCULAR BUFFER ------\n");
	return (TRUE);
}

int		add_str_in_buffer(CircularBuffer **cb, char *str)
{
	int	i;

	i = 0;
	printf("---- ADDING STR ------\n");
	while (str[i] != 0)
	{
		printf("---- ADDING STR %d & ADDR = %p------\n", i, (*cb));
		(*cb)->c = str[i];
		cb = &(*cb)->next;
		i++;
	}
	if (str[i - 1] == '\n')
		return (TRUE);
	return (FALSE);
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
    		printf("current = %p && next = %p && head = %p && c = %d\n", it, it->next, it->head, it->c);
			it = it->next;
		}

	}
	else
	{
		for (i = 0; it->c != 48; i++)
		{
    		printf("current = %p && next = %p && head = %p && c = %d\n", it, it->next, it->head, it->c);
    		it = it->next;
		}
	}
}