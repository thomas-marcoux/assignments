#include <iostream>
#include "language.h"


int	main(int argc, char *argv[])
{
  std::string	input_file;
  if (argc < 2)
    {
      std::cout << "Error" << std::endl;
      return 0;
    }
  else
    input_file = argv[1];
  std::ifstream	lang_if(DEFAULT_LANGUAGE_FILE), input;
  Language	l(lang_if);
  input.open(input_file.c_str(), std::fstream::in);
  l.parse(input);
  lang_if.close();
  input.close();
  return 1;
}
