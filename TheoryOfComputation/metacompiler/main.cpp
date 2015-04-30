#include <iostream>
#include "language.h"


int	main(int argc, char *argv[])
{
  if (argc != 2)
    return 0;
  std::ifstream	lang_if, input(DEFAULT_INPUT_FILE);
  std::string	language_file = argv[1];
  lang_if.open(language_file.c_str(), std::fstream::in);

  Language	l(lang_if);
  l.parse(input);
  lang_if.close();
  input.close();
  return 1;
}
