/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Fri Apr  7 17:58:30 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "line.h"
#include "commands.h"
#include <unistd.h>
#include <stdlib.h>

void	display_prompt()
{
   char	tmp[4097];
   char	**dir;
   int	size;

   dir = split(getcwd(tmp, 4096), '/');
   size = my_strstrlen(dir);
   if (size > 1)
     my_putstr(dir[size - 2]);
   if (size)
     {
       if (size > 1)
	 my_putchar('/');
       my_putstr(dir[size - 1]);
     }
   my_putchar('>');
   free_wordtab(dir);
}

int	main(int argc, char **argv, char **env)
{
  char  *cmd;
  int	value;

  value = 0;
  if (!env)
    return (84);
  while (1)
    {
      if (isatty(0))
	display_prompt();
      cmd = get_next_line(0);
      if (!cmd)
	{
	  my_putchar('\n');
	  return (0);
	}
      value = multi_commands(cmd, &env);
      if (cmd)
	free(cmd);
    }
  return (value);
}
