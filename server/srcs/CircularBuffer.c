/*
** CircularBuffer.c for CircularBuffer.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:05:22 2014 Flavien David
** Last update sam. juil.  12 18:05:22 2014 Flavien David
*/

#include "CircularBuffer.h"

int			create_elem_in_buffer(t_circular_buffer *cb, char c)
{
  t_circular_buffer	*node;

  if ((node = malloc(sizeof(t_circular_buffer))) == NULL)
    return (FALSE);
  node->c = c;
  node->next = cb->next;
  node->head = cb->head;
  cb->next = node;
  return (TRUE);
}

int			create_circular_buffer(t_circular_buffer **cb)
{
  t_circular_buffer	*tmp;
  int			i;

  i = 0;
  (*cb)->c = BUFFER_CHAR;
  (*cb)->head = (*cb);
  (*cb)->next = (*cb);
  tmp = (*cb);
  while (i < BUFFER_SIZE)
    {
      create_elem_in_buffer(tmp, BUFFER_CHAR);
      tmp = tmp->next;
      i++;
    }
  return (TRUE);
}

int			add_str_in_buffer(t_circular_buffer **cb, char *str)
{
  t_circular_buffer	*tmp;
  int			i;

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

void			reset_elem_in_buffer(t_circular_buffer **cb,
					     int nb_char)
{
  t_circular_buffer	*tmp;
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

char	*get_data_of_buffer(t_circular_buffer *cb)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
    return (NULL);
  str = memset(str, 0, BUFFER_SIZE);
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
