/*
** exec.c for minishell in /home/raphael.goulmot/rendu/Bootstrap_Minishell
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Jan  4 09:08:05 2017 Raphaël Goulmot
** Last update Fri Apr  7 14:15:46 2017 Raphaël Goulmot
*/

#include "exec.h"
#include "utils.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int	is_regular_file(const char *path)
{
  struct stat	path_stat;

  stat(path, &path_stat);
  return (S_ISREG(path_stat.st_mode));
}

int	child(int pid, char type)
{
  int	status;

  waitpid(pid, &status, 0);
  if (WIFEXITED(status))
    status = WEXITSTATUS(status);
  my_error(status == 136 && !type, "Floating exception (core dumped)\n");
  my_error(status == 8 && !type, "Floating exception\n");
  my_error(status == 139 && !type, "Segmentation fault (core dumped)\n");
  my_error(status == 11 && !type, "Segmentation fault\n");
  status = status == 8 ? 136 : status == 11 ? 139 : status;
  kill(pid, -1);
  return (status);
}

int    exec(char **vars, char type)
{
  int   childpid;

  if ((childpid = fork()) == 0)
    {
      if (vars && vars[0] && is_regular_file(vars[0])
	  && access(vars[0], X_OK) != -1)
	execve(vars[0], vars, 0);
      else
	{
	  if (!type)
	    {
	      my_putstr_err("bash: ");
	      my_putstr_err(vars[0]);
	      my_putstr_err(": No such file or directory\n");
	    }
	  exit(-1);
	}
    }
  else
    return (child(childpid, type));
}
