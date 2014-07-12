/*
** cmd.c for cmd.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:06:30 2014 Flavien David
** Last update sam. juil.  12 18:06:30 2014 Flavien David
*/

#include "cmd.h"
#include "Server.h"
#include "CircularBuffer.h"

int 	set_cmd_information(t_server *, t_player *, t_cmd *, char *);
char	**my_str_to_wordtab(char *);
void	my_free_str_to_wordtab(char **);

int 	get_cmd_type(t_server *s, char *cmd)
{
  int	i;

  i = -1;
  if (cmd != NULL)
    {
      while (++i < 12)
	{
	  if (strncmp(s->cmd_type[i], cmd, strlen(s->cmd_type[i])) == 0)
	    return (i);
	}   
    }
  return (-1);
}

int	set_cmd_information(t_server *s, t_player *p, t_cmd *new_cmd, char *cmd)
{
  int	good;

  good = TRUE;
  new_cmd->cmd = my_str_to_wordtab(cmd);
  new_cmd->func = NULL;
  new_cmd->time = 0.0;
  new_cmd->team_name = NULL;
  if ((new_cmd->type = get_cmd_type(s, new_cmd->cmd[0])) == -1)
    good = FALSE;
  if (good == TRUE)
    {
      new_cmd->time = s->time_tab[new_cmd->type];
      new_cmd->func = s->cmd_tab[new_cmd->type];
    }
  new_cmd->owner = p;
  new_cmd->num_cmd = p->nb_request;
  new_cmd->next = NULL;
  return (TRUE);
}

t_cmd		*create_new_cmd(void *s, t_player *p, char *cmd)
{
  t_cmd		*new_cmd;
  t_server	*server;

  server = (t_server *)s;
  if (!(new_cmd = malloc(sizeof(t_cmd))))
    return (NULL);
  if (set_cmd_information(server, p, new_cmd, cmd) == FALSE)
    {
      free(new_cmd->cmd);
      free(new_cmd);
      return (NULL);
    }
  return (new_cmd);
}

int		add_cmd_in_list(t_cmd **list, t_cmd *new_cmd)
{
  t_cmd		*tmp;
  t_cmd		*save;

  tmp = (*list);
  save = NULL;
  while (tmp)
    {
      if (tmp->num_cmd == new_cmd->num_cmd)
	{
	  new_cmd->next = tmp->next;
	  tmp->next = new_cmd;
	  return (TRUE);
	}
      save = tmp;
      tmp = tmp->next;
    }
  if (!save)
    (*list) = new_cmd;
  else
    save->next = new_cmd;
  return (TRUE);
}

int		del_cmd_in_list(t_cmd **list, t_cmd *cmd)
{
  t_cmd		*tmp;
  t_cmd		*save;

  tmp = *list;
  if (tmp == cmd)
    {
      *list = tmp->next;
      return (TRUE);
    }
  else
    {
      while (tmp)
	{
	  if (tmp->next == cmd)
	    {
	      my_free_str_to_wordtab(cmd->cmd);
	      save = tmp->next;
	      tmp->next = tmp->next->next;
	      free(save);
	      return (TRUE);
	    }
	  tmp = tmp->next;
	}
    }
  return (FALSE);
}
