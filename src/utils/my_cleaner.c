/*
** my_cleaner.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr  1 03:35:19 2017 Raphaël Goulmot
** Last update Sat Apr  1 05:30:44 2017 Raphaël Goulmot
*/

#include "utils.h"

void	clean_space_tab(char *str)
{
  int	i;
  int	tmp;
  int	size;

  i = 0;
  tmp = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i);
  if (i > 0)
    {
      tmp = 0;
      size = my_strlen(str);
      while (tmp < size - i)
	str[tmp++] = str[i + tmp - 1];
      str[tmp] = 0;
    }
  i = my_strlen(str) - 1;
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && --i);
  if (i != my_strlen(str) - 1)
    str[i + 1] = 0;
}

void    clean_double_space(char *contents)
{
  int   i;
  int   tmp;

  i = tmp = 0;
  while (contents[i])
    {
      if (!i || (i > 0 && !(contents[i] == ' '
			    && contents[i - 1] == ' ')))
	contents[tmp++] = contents[i];
      i++;
    }
  contents[tmp] = 0;
}

void    replace_tab_by_space(char *contents)
{
  int   i;

  i = 0;
  while (contents[i])
    if (contents[i++] == '\t')
      contents[i - 1] = ' ';
}
