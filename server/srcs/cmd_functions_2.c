#include <string.h>
#include "cmd_functions.h"

int concat_texte(t_cmd *new_cmd)
{
  int i;
  int len;
  char *s;

  if (new_cmd->type == BROADCAST_TEXTE)
  {
    i = 1;
    len = 0;
    while (new_cmd->cmd[i])
      {
          len += strlen(new_cmd->cmd[i]) + 1;
          ++i;
      }
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