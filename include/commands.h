/*
** commands.h for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell1
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Jan 20 01:21:29 2017 Raphaël Goulmot
** Last update Sat Apr  1 04:54:14 2017 Raphaël Goulmot
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

typedef struct	s_functions
{
  char	*name;
  void	(*ptsFunction)(char **, char **);
}		t_functions;

t_functions	*get_all_functions();
void	(*get_function(char *))(char **, char **);
int	count_args(char **);
char	*get_var(char **, char *);
void	commands(char *, char **);
void	my_exit(char **, char **);
void	my_env(char **, char **);
void	my_cd(char **, char **);

#endif
