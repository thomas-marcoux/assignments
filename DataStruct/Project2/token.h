#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class	Token
{
 public:
  Token(std::string const&);
  ~Token();
  void	addToken(Token*);
  Token*	getNext() const;
  std::string	getItem() const;
  void	print() const;
  bool	operator==(std::string);
 private:
  std::string	item;
  Token*	next;
};

#endif
