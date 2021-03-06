#include <iostream>
#include "language.h"

//Read from in and map states to the transition matrix
Language::Language(std::ifstream &in)
{
  in >> alphabet >> states >> nb_symbols;
  matrix = new std::map<char, int>[states];
  for (int i = 0; i < states; ++i)
    for (int j = 0; j < nb_symbols; ++j)
      in >> matrix[i][alphabet[j]];
  for (int key; in >> key;)
    std::getline(in, messages[key]);
  messages[ERROR_WRONG_SYMBOL] = WRONG_SYMBOL_MESSAGE;
}

Language::~Language()
{
  delete[] matrix;
}

//State Transition Machine
int	Language::parse(std::string s, int current_state)
{
  if (current_state >= ERROR_STATE || !s.length())
    return current_state;
  return parse(s.substr(1, s.length() - 1), matrix[current_state][s[0]]);
}

//Returns true if the string is composed of the language's alphabet
bool	Language::alphabet_is_correct(std::string s)
{
  for (int i = 0, l = s.length(); i < l; ++i)
    if (alphabet.find(s[i]) == std::string::npos)
      return false;
  return true;
}

//Parse all the strings from in and outputs the results
int	Language::parse(std::ifstream &in)
{
  int	key;

  for (std::string s; in >> s;)
    {
      if (!alphabet_is_correct(s))
	key = ERROR_WRONG_SYMBOL;
      else
	key = parse(s, DEFAULT_STATE);
      std::cout << s << ": " << messages[key] << std::endl;
    }
}
