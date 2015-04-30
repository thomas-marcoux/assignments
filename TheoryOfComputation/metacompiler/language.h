#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <fstream>
#include <map>
#include <string>

#define DEFAULT_INPUT_FILE	"input.txt"
#define DEFAULT_LANGUAGE_FILE	"language.txt"
#define	DEFAULT_STATE		0
#define	ERROR_STATE		10000
#define	ERROR_WRONG_SYMBOL	ERROR_STATE
#define WRONG_SYMBOL_MESSAGE	"Invalid symbol."

class	Language
{
 private:
  std::string			alphabet;
  int				states;
  int				nb_symbols;
  std::map<char, int>		*matrix;
  std::map<int, std::string>	messages;

 public:
  Language(std::ifstream&);
  ~Language();
  bool	alphabet_is_correct(std::string);
  int	parse(std::string, int);
  int	parse(std::ifstream&);
};

#endif
