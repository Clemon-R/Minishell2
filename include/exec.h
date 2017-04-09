/*
** exec.h for minishell in /home/raphael.goulmot/rendu/PSU_2016_minishell1
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Jan 20 02:42:05 2017 Raphaël Goulmot
** Last update Sun Apr  9 19:42:20 2017 Raphaël Goulmot
*/

#ifndef EXEC_H_
# define EXEC_H_

int	is_regular_file(const char *);
int	exec(char **, char, int *, char);

#endif
