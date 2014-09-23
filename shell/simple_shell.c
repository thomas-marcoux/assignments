#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "shell.h"

// Function parsing user input to tokens in args. Returns args.
char**	get_tokens(char **args, char *input)	{
  int	i;

  if (!input)
    return NULL;
  args[0] = strtok(input, DELIM);
  for (i = 1; (args[i] = strtok(NULL, DELIM)); ++i);
  return args;
}

// Returns True if an input is a built-in command.
int	is_built_in(char **args)	{
  if (!strcmp(args[0], "exit") ||
      !strcmp(args[0], "history") ||
      !strncmp(args[0], "!", 1))
    return (1);
  return (0);
}

// Executes built-in commands. Returns a flag.
int	built_in(char **args, char **history)	{
  if (!strcmp(args[0], "exit"))
    return (0);
  if (!strcmp(args[0], "history"))
    show_history(history);
  if (!strcmp(args[0], "!!"))
    return (call_history(args, history, 0));
  if (args[0][0] == '!' && IS_NUM(args[0][1]))
    return (call_history(args, history, CHAR_TO_NUM(args[0][1]) - 1));
  return (1);
}

// Executes any command. Returns a flag indicating if the shell should keep running
int	exec(char **args, char **history)	{
  pid_t	pid;

  if (!args | !args[0])
    return (1);
  if (is_built_in(args))
    return (built_in(args, history));
  pid = fork();
  if (pid < 0) 
    return (0);
  else if (!pid)	{
    if ((execvp(args[0], args)) < 0)
      printf("An error occured trying to execute %s\n", args[0]);
  }
  else
    wait(NULL);
  return (1);
}

// Main loop.
int	main(void)	{
  char	*args[MAX_LINE / 2 + 1];
  char	*history[MAX_LINE];
  char	input[MAX_LINE];
  int	input_size;
  int	should_run = 1;
  int	i;

  for (i = 0; i < HIST_SIZE; ++i)
    history[i] = NULL;
  while (should_run)	{
    printf("osh>");
    fflush(stdout);
    input_size = read(1, input, MAX_LINE);
    if (input_size < 0)
      return (0);
    input[input_size] = '\0';
    get_tokens(args, input);
    if (!is_built_in(args))
      add_to_history(history, input);
    should_run = exec(args, history);
  }
  for (i = 0; i < HIST_SIZE; ++i)
    free(history[i]);
  return (1);
}
