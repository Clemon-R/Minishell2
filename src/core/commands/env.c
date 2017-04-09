/*
** env.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr  1 04:51:24 2017 Raphaël Goulmot
** Last update Sun Apr  9 17:11:51 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

char	my_is_alphanumeric(char *str)
{
  while (*str)
    {
      if (!(my_char_isalpha(*str) || (*str >= '0' && *str <= '9')
	    || *str == '_'))
	return (0);
      str++;
    }
  return (1);
}

int	my_env(char ***env, char **useless)
{
  char	**clone;

  clone = *env;
  while (clone && *clone)
    {
      my_putstr(*clone++);
      my_putchar('\n');
    }
  return (0);
}

void	add_env(char ***env, int i, char *str)
{
  char	**new;
  int	index;
  char	**clone;

  index = 0;
  if (i >= my_strstrlen(*env))
    {
      new = malloc(sizeof(char *) * (my_strstrlen(*env) + 1) + sizeof(char)
		   * (my_strlen(str) + 1));
      clone = *env;
      while (clone && *clone++)
	new[index++] = *(clone - 1);
      new[index++] = str;
      new[index] = 0;
      *env = new;
    }
  else
    (*env)[i] = str;
}

int	my_setenv(char ***env, char **args)
{
  int	size;
  char	**line;
  char	*value;
  int	i;

  size = env ? my_strstrlen(args) : 0;
  if (!(i = 0) && size == 1)
    return (my_env(env, args));
  else if (size >= 2 && size <= 3 && my_is_alphanumeric(args[1]) && !(value=0))
    {
      while (!value && *env && (*env)[i] && (line = split((*env)[i], '=')))
	{
	  if (line && my_strstrlen(line) && my_strcmp(line[0], args[1]))
	    value = (*env)[i];
	  i += !value ? 1 : 0;
	  free_wordtab(line);
	}
      value = my_strcpy(args[1], "=");
      add_env(env, i, my_strcpy(value, (size > 2 ? args[2] : "")));
      free(value);
    }
  else
    my_putstr_err(size > 3 ? "setenv: Too many arguments.\n" :
	     "setenv: Variable name must contain alphanumeric characters.\n");
  return (size > 3 ? 1 : 0);
}

int	my_unsetenv(char ***env, char **args)
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
      while (args && *(++args) && !(find = 0) && (clone = *env))
	{
	  while (clone && *clone && (line=split(*clone++, '=')))
	    {
	      if (line && my_strstrlen(line) && my_strcmp(line[0], *args))
		find = 1;
	      else
		*(clone - 1 - find) = *(clone - 1);
	      if (line)
		free_wordtab(line);
	    }
	  *(clone - find) = 0;
	}
    }
  return (size == 1 ? 1 : 0);
}
