#include "List.h"
#include "Server.h"

int       add_elem(Player **front_ptr, int fd, int width, int height)
{
  Player	*node;
  Player	*tmp;

  node = malloc(sizeof(Player));
  if (node == NULL)
    return (-1);
  init_player(node, fd, width, height);
  node->next = NULL;
  tmp = *front_ptr;
  if (tmp == NULL)
    *front_ptr = node;
  else
  {
    while (tmp->next != NULL)
      tmp = tmp->next;
    tmp->next = node;
  }
  return (0);
}

int	      del_elem(Player **front_ptr, int fd)
{
  Player	*tmp;

  tmp = *(front_ptr);
  if (tmp && tmp->fd == fd)
  {
    *front_ptr = tmp->next;
    free(tmp);
    return (0);
  }
  while (tmp)
  {
    if (tmp->next && tmp->next->fd == fd)
    {
      tmp->next = tmp->next->next;
      return (0);
    }
    tmp = tmp->next;
  }
  return (1);
}

int	      get_max_fd(Player *front_ptr)
{
  Player	*tmp;
  int	max;

  tmp = front_ptr;
  max = 0;
  if (tmp)
  {
    while (tmp != NULL)
    {
      if (tmp->fd > max)
        max = tmp->fd;
      tmp = tmp->next;
    }
  }
  else
    return (0);
  return (max + 1);
}

void      display_list(Player *front_ptr)
{
  Player  *tmp;
  int     i = 0;

  tmp = front_ptr;
  if (!tmp)
    printf("NULL\n");
  while (tmp)
  {
    printf("%d : %d\n", i, tmp->fd);
    i++;
    tmp = tmp->next;
  }
}