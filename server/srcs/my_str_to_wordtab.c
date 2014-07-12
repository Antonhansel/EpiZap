/*
** my_str_to_wordtab.c for my_str_to_word_tab.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:08:12 2014 Flavien David
** Last update sam. juil.  12 18:08:12 2014 Flavien David
*/

#include <stdlib.h>
#include <string.h>

int	count_words(const char *);
char	*find_word(char *);
int	get_word_len(const char *);

int	count_words(const char *s)
{
  int	i;
  int	nb_words;

  i = 0;
  nb_words = 0;
  while (s && s[i])
    {
      if (s[i] != ' ' && s[i] != '\t')
	{
	  ++nb_words;
	  while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	    ++i;
	}
      else
	++i;
    }
  return (nb_words);
}

char	*find_word(char *s)
{
  int	i;

  i = 0;
  while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
    ++i;
  return (&s[i]);
}

int	get_word_len(const char *s)
{
  int	i;

  i = 0;
  while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
    ++i;
  return (i);
}

char	**my_str_to_wordtab(char *s)
{
  char	**tab;
  int	nb_words;
  int	word_len;
  int	i;

  nb_words = count_words(s);
  if (!(tab = malloc(sizeof(char *) * (nb_words + 1))))
    return (NULL);
  i = 0;
  while (i < nb_words)
    {
      s = find_word(s);
      word_len = get_word_len(s);
      if (!(tab[i] = strndup(s, word_len)))
	return (NULL);
      s = &s[word_len + 1];
      ++i;
    }
  tab[i] = '\0';
  return (tab);
}

void	my_free_str_to_wordtab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
