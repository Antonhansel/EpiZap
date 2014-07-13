/*
** cmd_functions_2.c for cmd_functions_2.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  dim. juil.  13 13:48:37 2014 Flavien David
** Last update dim. juil.  13 13:48:37 2014 Flavien David
*/

#include <string.h>
#include "cmd_functions.h"
#include "List.h"

int	concat_texte(t_cmd *new_cmd)
{
  int	i;
  int	len;
  char	*s;

  if (new_cmd->type == BROADCAST_TEXTE)
    {
      i = 0;
      len = 0;
      while (new_cmd->cmd[++i])
	len += strlen(new_cmd->cmd[i]) + 1;
      if (!(s = malloc(sizeof(char) * (len + 1))))
	return (FALSE);
      i = 1;
      while (new_cmd->cmd[i])
	{
	  strcat(s, new_cmd->cmd[i]);
	  if (new_cmd->cmd[i + 1])
	    strcat(s, " ");
	  ++i;
	}
      new_cmd->cmd[1] = s;
    }
  return (TRUE);
}

int		destroy_player(t_player *this, void *p)
{
  t_server	*s;
  t_team	*tmp;

  s = ((t_server *)(p));
  tmp = s->team;
  while (tmp)
    {
      if (this->team_name && strcmp(tmp->name, this->team_name) == 0)
	{
	  if (del_elem(&tmp->player_list, this->fd) == 0)
	    tmp->nb_player_actu--;
	}
      tmp = tmp->next;
    }
  free(this->inventory);
  free(this->team_name);
  return (0);
}
