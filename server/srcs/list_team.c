#include "list_team.h"

int     add_elem_in_team(Team **front_ptr, char *name, int nb)
{
  Team	*node;
  Team	*tmp;

  node = malloc(sizeof(Team));
  if (node == NULL)
    return (FALSE);
  init_team(node, name, nb);
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
  return (TRUE);
}

int     del_elem_in_team(Team **front_ptr, char *name)
{
  Team	*tmp;

  tmp = *(front_ptr);
  if (tmp && strcmp(name, tmp->name) == 0)
  {
    *front_ptr = tmp->next;
    free(tmp);
    return (TRUE);
  }
  while (tmp)
  {
    if (tmp->next && strcmp(name, tmp->next->name) == 0)
    {
      tmp->next = tmp->next->next;
      return (TRUE);
    }
    tmp = tmp->next;
  }
  return (FALSE);
}