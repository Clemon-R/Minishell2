/*
** commands.h for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell1
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Jan 20 01:21:29 2017 Raphaël Goulmot
** Last update Fri Apr  7 17:55:57 2017 Raphaël Goulmot
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

typedef struct	s_functions
{
  char	*name;
  int	(*ptsFunction)(char ***, char **);
}		t_functions;

t_functions	*get_all_functions();
int	(*get_function(char *))(char ***, char **);
int	count_args(char **);
char	*get_var(char **, char *);
int	commands(char *, char ***);
int	multi_commands(char *, char ***);
int	my_exit(char ***, char **);
int	my_env(char ***, char **);
int	my_setenv(char ***, char **);
int	my_unsetenv(char ***, char **);
int	my_cd(char ***, char **);

#endif
