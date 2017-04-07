/*
** multi_commands.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr  7 14:55:41 2017 Raphaël Goulmot
** Last update Fri Apr  7 17:58:39 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "commands.h"

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
      value = commands(cmds[i++], env);
  return (value);
}
