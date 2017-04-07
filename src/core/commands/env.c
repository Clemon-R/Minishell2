/*
** env.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr  1 04:51:24 2017 Raphaël Goulmot
** Last update Fri Apr  7 14:51:50 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

char	my_is_alphanumeric(char *str)
{
  while (*str)
    {
      if (!(my_char_isalpha(*str) || my_char_isnumeric(*str) || *str == '_'))
	return (0);
      str++;
    }
  return (1);
}

int	my_env(char **env, char **useless)
{
  while (env && *env)
    {
      my_putstr(*env++);
      my_putchar('\n');
    }
  return (0);
}

int	my_setenv(char **env, char **args)
{
  int	size;
  char	**line;
  char	*value;

  size = env ? my_strstrlen(args) : 0;
  if (size == 1)
    return (my_env(env, args));
  else if (size >= 2 && size <= 3 && my_is_alphanumeric(args[1]) && !(value=0))
    {
      while (!value && env && *env && (line = split(*env, '=')))
	{
	  if (line && my_strstrlen(line) && my_strcmp(line[0], args[1]))
	    value = *env;
	  env += !value ? 1 : 0;
	  free_wordtab(line);
	}
      value = my_strcpy(args[1], "=");
      (env ? *env++ = my_strcpy(value, size == 2 ? args[2] : "") : 0);
      free(value);
      (env ? *env = 0 : 0);
    }
  else
    my_putstr_err(size > 3 ? "setenv: Too many arguments.\n" :
	     "setenv: Variable name must contain alphanumeric characters.\n");
  return (size > 3 ? 1 : 0);
}

int	my_unsetenv(char **env, char **args)
{
  int	size;
  char	**clone;
  char	find;
  char	**line;

  size = my_strstrlen(args);
  if (size == 1)
    my_putstr_err("unsetenv: Too few arguments.\n");
  else
    {
      while (args && *(++args) && !(find = 0))
	{
	  clone = env;
	  while (clone && *clone && ++clone && (line=split(*(clone - 1), '=')))
	    {
	      if (line && my_strstrlen(line) && my_strcmp(line[0], *args))
		find = 1;
	      *(clone - 1 - find) = *(clone - 1);
	      if (line)
		free_wordtab(line);
	    }
	  *(clone - find - 1) = 0;
	}
    }
  return (size == 1 ? 1 : 0);
}
