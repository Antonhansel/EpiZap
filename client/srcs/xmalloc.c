#include <stdio.h>
#include <stdlib.h>

void		*xmalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		perror("malloc");
	return (ptr);
}