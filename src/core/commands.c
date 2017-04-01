/*
** commands.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell1
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Fri Jan 20 01:21:03 2017 Raphaël Goulmot
** Last update Sat Apr  1 05:21:17 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "commands.h"
#include "exec.h"
#include <stdlib.h>
#include <unistd.h>

t_functions	*get_all_functions()
{
  t_functions	*list;

  list = malloc(sizeof(t_functions) * 3);
  list[0].name = "cd";
  list[0].ptsFunction = &my_cd;
  list[1].name = "exit";
  list[1].ptsFunction = &my_exit;
  list[2].name = "env";
  list[2].ptsFunction = &my_env;
  return (list);
}

void	(*get_function(char *str))(char **, char **)
{
  void	(*pts)(char **, char **);
  t_functions	*list;
  int	i;
  int	count;

  count = 0;
  pts = 0;
  list = get_all_functions();
  while (count++ < 3)
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

void	launch_args(char *path, char **env, char **args)
{
  char	**paths;
  char	*name;
  char	*tmp;
  char	check;

  if (args && args[0][0] != '.' && path && !my_strstr(args[0], "/")
    && (paths = split(path, ':')) && my_strstrlen(paths) && (check = -1) == -1)
    {
      while (check == -1 && *paths && !(tmp = 0))
	{
	  tmp = my_strcpy(*paths++, "/");
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
    exec(args, 0);
}

void	commands(char *arg, char **env)
{
  char	**args;
  char	*path;
  void	(*function)(char **, char **);

  clean_space_tab(arg);
  replace_tab_by_space(arg);
  clean_double_space(arg);
  if (!*arg || !(args = split(arg, ' ')) || !*args)
    {
      my_putchar(!isatty(0) ? '\n' : '\0');
      return;
    }
  my_error(!(path = get_var(env, "PATH")), "ERROR: Path not found !\n");
  function = get_function(args[0]);
  if (function)
    (*function)(env, args);
  else
    launch_args(path, env, args);
  free_wordtab(args);
}
