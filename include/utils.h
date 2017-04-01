/*
** utils.h for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Dec 15 14:35:14 2016 Raphaël Goulmot
** Last update Sat Apr  1 05:19:52 2017 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

void	my_putchar(char);
void	my_putstr(char *);
void	my_putstr_err(char *);
int	my_strlen(char *);
int	my_strstrlen(char **);
int	my_getnbr(char *);
void	my_put_nbr(int);
char	my_char_islower(char);
char	my_char_isupper(char);
char	my_char_isalpha(char);
char	my_char_isnumeric(char);
char	my_str_isnumeric(char *);
int	length_word(char *, int, char);
int	count_words(char *, char);
char	**split(char *, char);
char	*my_strcpy(char *, char *);
char	my_strstr(char *, char *);
char	my_strcmp(char *, char *);
void	free_wordtab(char **);
void	free_safe(char *);
void	clean_space_tab(char *);
void	clean_double_space(char *);
void	replace_tab_by_space(char *);
char	my_error(char, char *);

#endif /* !UTILS_H_ */
