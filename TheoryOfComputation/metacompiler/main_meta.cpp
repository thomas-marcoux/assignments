#include <iostream>
#include <unistd.h>
#include "language.h"

//Copies Language file to DEFAULT_LANGUAGE_FILE and compile compiler sources.
int	main(int argc, char *argv[])
{
  int	pid;

  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0] << " language_file" << std::endl;
      return 0;
    }
  pid = fork();
  if (pid == 0)
    execl("/bin/cp", "cp", argv[1], DEFAULT_LANGUAGE_FILE, NULL);
  pid = fork();
  if (pid == 0)
    execl("/usr/bin/g++", "g++", "language.cpp", "main.cpp", "-ocompiler", NULL);
  return 1;
}
