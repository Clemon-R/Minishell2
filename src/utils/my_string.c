/*
** my_string.c for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Mar  1 22:16:49 2017 Raphaël Goulmot
** Last update Mon Apr  3 13:50:40 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

void	free_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    free(tab[i++]);
  if (tab)
    free(tab);
  tab = 0;
}

void	free_safe(char *str)
{
  if (str)
    free(str);
  str = 0;
}

char	my_strstr(char *str, char *arg)
{
  char	*clone;
  int	i;
  char	check;

  clone = str;
  while (*clone && !(i = 0))
    {
      check = 0;
      while (*(clone + i) && arg[i] && !check)
	{
	  if (*(clone + i) != arg[i])
	    check = 1;
	  i++;
	}
      if (!check && my_strlen(arg) == i)
	return (1);
      clone++;
    }
  return (0);
}

char    *my_strcpy(char *str1, char *str2)
{
  char  *new;
  int   n;

  n = 0;
  new = malloc(sizeof(char) * ((str1 ? my_strlen(str1) : 0)
			       + (str2 ? my_strlen(str2) : 0) + 1));
  while (str1 && *str1)
    new[n++] = *str1++;
  while (str2 && *str2)
    new[n++] = *str2++;
  new[n] = '\0';
  return (new);
}

char    my_strcmp(char *str1, char *str2)
{
  int   i;

  i = 0;
  while ((str1[i] || str2[i]) && ++i)
    if (str1[i - 1] != str2[i - 1])
      return (0);
  return (1);
}
