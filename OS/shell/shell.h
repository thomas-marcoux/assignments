#ifndef __SHELL_H
#define __SHELL_H

#define MAX_LINE	80	/* The maximum length command */
#define	DELIM		" \n"	/* The delimiter characters to parse the user input */
#define	HIST_SIZE	10	/* The history's capacity */

//Macro returning True if character is an integer
#define	IS_NUM(c)	((c) >= 48 && (c) <= 57) ? 1 : 0
//Macro returning the character as an integer
#define	CHAR_TO_NUM(c)	(c) - 48

int	add_to_history(char **history, char *s);
void	show_history(char **history);
int	call_history(char **args, char **history, int n);

int	exec(char **args, char **history);
int	built_in(char **args, char **history);
char**	get_tokens(char **args, char *input);

#endif
