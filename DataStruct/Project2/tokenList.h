#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "token.h"

#define DELIMITER ' '

class	TokenList
{
 public:
  TokenList();
  TokenList(std::string&);
  ~TokenList();
  void	parseInput(std::string&);
  void	addToken(Token*);
  void	addToken(const char*);
  void	addToken(std::string);
  void	pushFront(std::string);
  void	print() const;
  Token*	getHead() const;
  int	evalPostfix();
 private:
  Token*	head;
  Token*	tail;
};

#endif
