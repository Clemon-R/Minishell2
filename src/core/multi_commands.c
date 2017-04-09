/*
** multi_commands.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr  7 14:55:41 2017 Raphaël Goulmot
** Last update Sun Apr  9 19:44:40 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "commands.h"
#include "line.h"
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int	multi_commands(char *arg, char ***env)
{
  char	**cmds;
  int	i;
  int	value;

  value = 0;
  if (!arg || !*arg)
    return (0);
  clean_space_tab(arg);
  replace_tab_by_space(arg);
  clean_double_space(arg);
  i = 0;
  if (arg && (cmds = split(arg, ';')))
    while (cmds[i] && cmds[i][0])
      value = pipe_commands(cmds[i++], env);
  return (value);
}

int	pipe_commands(char *line, char ***env)
{
  char	**args;
  int	pipefd[2];
  int	i;
  int	value;
  char	check;
  int	vars[3];

  value = i = check = vars[2] = 0;
  if (!(args = split(line, '|')))
    return (value);
  while (args && args[i])
    {
      pipe(vars);
      value = commands(args[i], env, vars, args[i + 1] != 0);
      vars[2] = vars[0];
      i++;
    }
  return (value);
}
