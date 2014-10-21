#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "token.h"

#define DELIMITER " "

class	TokenList
{
 public:
  TokenList(std::string&);
  ~TokenList();
  void	parseInput(std::string&);
  void	addToken(std::string&);
  void	addToken(Token*);
  void	print() const;
 private:
  Token*	head;
  Token*	tail;
};

#endif
