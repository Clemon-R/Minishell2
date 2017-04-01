/*
** exec.c for minishell in /home/raphael.goulmot/rendu/Bootstrap_Minishell
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Jan  4 09:08:05 2017 Raphaël Goulmot
** Last update Sat Apr  1 05:27:09 2017 Raphaël Goulmot
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
  if (status == 139 && !type)
    my_putstr_err("Segmentation fault (core dumped)\n");
  kill(pid, -1);
  return (status);
}

int    exec(char **vars, char type)
{
  int   childpid;

  if ((childpid = fork()) == 0)
    {
      if (is_regular_file(vars[0]) && access(vars[0], X_OK) != -1)
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
