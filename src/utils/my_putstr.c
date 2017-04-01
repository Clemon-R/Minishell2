/*
** my_putstr.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:08:09 2016 Raphaël Goulmot
** Last update Tue Dec 20 15:38:01 2016 Raphaël Goulmot
*/

#include "utils.h"
#include <unistd.h>

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
