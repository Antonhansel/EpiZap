#include "List.h"
#include "Server.h"

int       add_elem(Player **front_ptr, int fd)
{
  Player	*node;
  Player	*tmp;

  node = malloc(sizeof(Player));
  if (node == NULL)
    return (-1);
  init_player(node, fd);
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

int       add_player(Player **front_ptr, Player *player)
{
  Player  *node;
  Player  *tmp;

  node = malloc(sizeof(Player));
  if (node == NULL)
    return (-1);
  copy_player(node, player);
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