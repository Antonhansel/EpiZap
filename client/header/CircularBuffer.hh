#ifndef CIRCULAR_BUFFER_HH_
# define CIRCULAR_BUFFER_HH_

# define BUFFER_SIZE	512
# define BUFFER_CHAR	0

# include <iostream>
# include <string>
# include <stdlib.h>
# include <string.h>

typedef struct 				CircularBuffer
{
	/* data */
	char					c;
	struct CircularBuffer 	*next;
	struct CircularBuffer 	*head;
}							CircularBuffer;

bool	createCircularBuffer(CircularBuffer **);
void	displayCircularBuffer(CircularBuffer *, const int);
bool	addStrInBuffer(CircularBuffer **, const char *);
void 	resetElemInBuffer(CircularBuffer **, const int);
std::string	*getDataOfBuffer(CircularBuffer *cb);
void	clearCircularBuffer(CircularBuffer **);

#endif /* CIRCULAR_BUFFER_HH_ */