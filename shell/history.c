#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"

// Function adding a new entry to the history and cycling the old entries.
int	add_to_history(char **history, char *s)	{
  int	i = HIST_SIZE - 1;
  char	*buff;

  buff = malloc(sizeof(*buff) * MAX_LINE);
  if (history[i])
    free(history[i]);
  for (; i > 0; --i)
    history[i] = history[i - 1];
  history[i] = strcpy(buff, s);
}

// Prints the history.
void	show_history(char **history)	{
  int	i;

  for (i = HIST_SIZE - 1; i >= 0; --i)	{
    if (history[i])
      printf("%d %s\n", i + 1, history[i]);
  }
}

// Calls previous inputs from the history. Returns a flag.
int	call_history(char **args, char **history, int n)	{
  if (history[n] && n >= 0)	
    return (exec(get_tokens(args, history[n]), history));
  printf("No such command in history\n");
  return (1);
}
