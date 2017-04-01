/*
** env.c for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr  1 04:51:24 2017 Raphaël Goulmot
** Last update Sat Apr  1 04:53:19 2017 Raphaël Goulmot
*/

#include "utils.h"

void	my_env(char **env, char **useless)
{
  while (*env)
    {
      my_putstr(*env++);
      my_putchar('\n');
    }
}
