
int	    count_substr(char *str, char *delim)
{
  int	  i;
  int	  nb;

  i = 0;
  nb = 0;
  while (str && delim && str[i])
  {
    if (strncmp(&str[i], delim, strlen(delim)) != 0)
    {
     while (str[i] && strncmp(&str[i], delim, strlen(delim)) != 0)
     {
       i++;
     }
     nb++;
     if (str[i])
     {
       i += strlen(delim);
     }
   }
   else
   {
   }
 }
 return (nb);
}

char		*pass_delimiter(char *str, char *delim)
{
  unsigned int	i;
  unsigned int	len;

  i = 0;
  len = my_strlen(delim);
  while (str && str[i] && !my_strncmp(&str[i], delim, len))
  {
    i += len;
  }
  return (&str[i]);
}

char		**my_split_str_to_wordtab(char *str, char *delimiter)
{
  char		**tab;
  unsigned int	len;
  unsigned int	i;
  unsigned int	pos;

  len = count_substr(str, delimiter);
  if (!(tab = xmalloc(sizeof(char *) * (len + 1))))
  {
    return (NULL);
  }
  i = 0;
  while (i < len)
  {
    str = pass_delimiter(str, delimiter);
    if ((pos = my_strpos(str, delimiter)) == -1)
    {
     pos = my_strlen(str);
   }
   if (!(tab[i] = my_strndup(str, pos)))
   {
     return (NULL);
   }
   str = &str[pos];
   i++;
 }
 tab[i] = '\0';
 return (tab);
}
