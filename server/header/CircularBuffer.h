/*
** CircularBuffer.h for CircularBuffer.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:17:39 2014 Flavien David
** Last update sam. juil.  12 18:17:39 2014 Flavien David
*/

#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# include "Network.h"

# define BUFFER_SIZE	1024
# define BUFFER_CHAR	0

typedef struct			s_circular_buffer
{
  char				c;
  struct s_circular_buffer 	*next;
  struct s_circular_buffer 	*head;
}				t_circular_buffer;

int				create_circular_buffer(t_circular_buffer **);
void				display_circular_buffer(t_circular_buffer *,
							int);
int				add_str_in_buffer(t_circular_buffer **, char *);
void				reset_elem_in_buffer(t_circular_buffer **, int);
char				*get_data_of_buffer(t_circular_buffer *);
void				clear_circular_buffer(t_circular_buffer **);

#endif /* !CIRCULAR_BUFFER_H_ */
