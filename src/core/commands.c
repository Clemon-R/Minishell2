/*
** commands.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell1
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Fri Jan 20 01:21:03 2017 Raphaël Goulmot
** Last update Fri Apr  7 17:59:01 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "commands.h"
#include "exec.h"
#include <stdlib.h>
#include <unistd.h>

t_functions	*get_all_functions()
{
  t_functions	*list;

  list = malloc(sizeof(t_functions) * 5);
  list[0].name = "cd";
  list[0].ptsFunction = &my_cd;
  list[1].name = "exit";
  list[1].ptsFunction = &my_exit;
  list[2].name = "env";
  list[2].ptsFunction = &my_env;
  list[3].name = "setenv";
  list[3].ptsFunction = &my_setenv;
  list[4].name = "unsetenv";
  list[4].ptsFunction = &my_unsetenv;
  return (list);
}

int	(*get_function(char *str))(char ***, char **)
{
  int	(*pts)(char ***, char **);
  t_functions	*list;
  int	i;
  int	count;

  count = 0;
  pts = 0;
  list = get_all_functions();
  while (count++ < 5)
    {
      i = 0;
      while (str[i] && str[i] == list[count - 1].name[i] && ++i);
      if (i == my_strlen(str) && i == my_strlen(list[count - 1].name))
	pts = list[count - 1].ptsFunction;
    }
  free(list);
  return (pts);
}

char	*get_var(char **env, char *name)
{
  int	i;
  int	w;
  char	find;

  find = 0;
  while (*env && !find)
    {
      w = 0;
      find = 1;
      while (find && name[w++])
	if (name[w - 1] != (*env)[w - 1])
	  find = 0;
      env++;
    }
  if (find)
    return (env[-1] + my_strlen(name) + 1);
  else
    return (0);
}

int	launch_args(char *path, char **args)
{
  char	**paths;
  char	*name;
  char	*tmp;
  char	check;

  if (args && args[0][0] != '.' && !my_strstr(args[0], "/") && (check= -1)==-1)
    {
      paths = path ? split(path, ':') : 0;
      while (check == -1 && paths && *paths && (tmp =my_strcpy(*paths++, "/")))
	{
	  name = my_strcpy(tmp, args[0]);
	  free(tmp);
	  tmp = args[0];
	  args[0] = name;
	  check = exec(args, 1);
	  args[0] = tmp;
	  free(name);
	}
      my_error(check == -1, args[0]);
      my_error(check == -1, ": Command not found.\n");
    }
  else
    check = exec(args, 0);
  return (check != -1 ? check : 1);
}

int	commands(char *arg, char ***env)
{
  char	**args;
  char	*path;
  int	(*function)(char ***, char **);
  int	value;

  value = 0;
  clean_space_tab(arg);
  if (!*arg || !(args = split(arg, ' ')) || !*args)
    {
      my_putchar(!isatty(0) ? '\n' : '\0');
      return (0);
    }
  path = get_var(*env, "PATH");
  function = get_function(args[0]);
  if (function)
    if (!isatty(0))
      value = ((*function)(env, args));
    else
      (*function)(env, args);
  else
    value = (launch_args(path, args));
  free_wordtab(args);
  return (value);
}
