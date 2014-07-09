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

int       add_square(Player **front_ptr, Player *player)
{
  Player  *tmp;

  tmp = *front_ptr;
  if (tmp == NULL)
  {
    *front_ptr = player;
    player->next_square = NULL;
  }
  else
  {
    while (tmp->next_square)
      tmp = tmp->next_square;
    tmp->next_square = player;
    player->next_square = NULL;
  }
  return (0);
}

int       del_square(Player **front_ptr, int fd)
{
  Player  *tmp;
  Player  *tmp1;

  tmp = *(front_ptr);
  if (tmp && tmp->fd == fd)
  {
    *front_ptr = tmp->next_square;
    return (0);
  }
  while (tmp->next_square)
  {
    if (tmp->next_square->fd == fd)
    {
      tmp1 = tmp->next_square;
      tmp->next_square = tmp1->next_square;
      tmp1->next_square = NULL;
      return (0);
    }
    tmp = tmp->next_square;
  }
  return (1);
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

/*void      display_list(Player *front_ptr)
{
  Player  *tmp;
  int     i = 0;

  printf("-----------------> %p\n", front_ptr);
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
*/
void      display_list_square(Player *front_ptr)
{
  Player  *tmp;
  int     i = 0;

  printf("---- DISPLAY LIST BEGIN ----\n");
  tmp = front_ptr;
  if (!tmp)
    printf("NULL\n");
  while (tmp)
  {
    printf("%d : %d\n", i, tmp->fd);
    i++;
    tmp = tmp->next_square;
  }
  printf("---- DISPLAY LIST END ----\n");
}