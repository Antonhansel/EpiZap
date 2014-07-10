#include "CircularBuffer.hh"

bool 				createElemInBuffer(CircularBuffer *cb, char c)
{
	CircularBuffer	* node;

	if ((node = (CircularBuffer*)malloc(sizeof(CircularBuffer))) == NULL)
		return (false);
	node->c = c;
	node->next = cb->next;
	node->head = cb->head;
	cb->next = node;
	return (true);
}

bool				createCircularBuffer(CircularBuffer **cb)
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
		if (createElemInBuffer(tmp, BUFFER_CHAR) == false)
			return (false);
		tmp = tmp->next;
		i++;
	}
	return (true);
}

bool				addStrInBuffer(CircularBuffer **cb, const char *str)
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
		return (true);
	return (false);
}

void 				resetElemInBuffer(CircularBuffer **cb, int nb_char)
{
	CircularBuffer 	*tmp;
	int 			i;

	i = 0;
	tmp = (*cb)->head;
	while (i < nb_char)
	{
		tmp->c = BUFFER_CHAR;
		++i;
		tmp = tmp->next;
	}
}

std::string	*getDataOfBuffer(CircularBuffer *cb)
{
	int				i;
	std::string		*s;

	i = 0;
	cb = cb->head;
	s = new std::string("");
	if (cb->c != BUFFER_CHAR)
	{
		while (cb->c != BUFFER_CHAR && i < BUFFER_SIZE)
		{
			s->push_back(cb->c);
			cb = cb->next;
			++i;
		}
		return (s);
	}
	return (NULL);
}