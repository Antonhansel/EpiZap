/*
** my_split_str_to_wordtab.c for my_split_str_to_word_tab.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:08:00 2014 Flavien David
** Last update sam. juil.  12 18:08:00 2014 Flavien David
*/

#include <stdlib.h>
#include <string.h>

int	count_substr(char *str, char *delim)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str && delim && str[i])
    {
      if (strncmp(&str[i], delim, strlen(delim)) != 0)
	{
	  while (str[i] && strncmp(&str[i], delim, strlen(delim)) != 0)
	    i++;
	  nb++;
	  if (str[i])
	    i += strlen(delim);
	}
      else
	i += strlen(delim);
    }
  return (nb);
}

char	*pass_delimiter(char *str, char *delim)
{
  int	i;
  int	len;

  i = 0;
  len = strlen(delim);
  while (str && str[i] && !strncmp(&str[i], delim, len))
    i += len;
  return (&str[i]);
}

char	**my_split_str_to_wordtab(char *str, char *delimiter)
{
  char	**tab;
  int	len;
  int	i;
  int	pos;

  len = count_substr(str, delimiter);
  if (!(tab = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  i = 0;
  while (i < len)
    {
      str = pass_delimiter(str, delimiter);
      if ((pos = my_strpos(str, delimiter)) == -1)
	pos = strlen(str);
      if (!(tab[i] = strndup(str, pos)))
	return (NULL);
      str = &str[pos];
      i++;
    }
  tab[i] = '\0';
  return (tab);
}
