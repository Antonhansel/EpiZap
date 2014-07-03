#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# include "Network.h"

# define BUFFER_SIZE	64
# define BUFFER_CHAR	48

typedef struct 				CircularBuffer
{
	/* data */
	char					c;
	struct CircularBuffer 	*next;
	struct CircularBuffer 	*head;
}							CircularBuffer;

int		create_circular_buffer(CircularBuffer **);
void	display_circular_buffer(CircularBuffer *, int);
int		add_str_in_buffer(CircularBuffer **, char *);
void 	reset_elem_in_buffer(CircularBuffer **, int);
char 	*get_data_of_buffer(CircularBuffer *);
void	clear_circular_buffer(CircularBuffer **);

#endif