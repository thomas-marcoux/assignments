/* CPSC2380 
 * Department of Computer Science, UALR 
 * Project 3
 * Student Name: Thomas Marcoux
 * Student UALR ID (last four digits): 5564
 * Project Descriptions: 
 * This project takes an arithmetic expression as input,
 * converts it to postfix, then to a binary tree which it prints
 * along with its infix, postfix and prefix expression
 * as well as the evaulation of the tree.
 * Project Due Date: 12/4/2014 
 * Project Revised Date: 11/30/2014, 12/03/2014 
 */

#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "token.h"

enum	State {
  STATE0,
  STATE1,
  STATE2,
  STATE3,
  STATE4
};

class	TokenList
{
 public:
  TokenList();
  TokenList(std::string&);
  ~TokenList();
  int		parseInput(std::string&);
  void		addToken(Token*);
  void		addToken(std::string);
  void		print() const;
  Token*	getHead() const;
  bool		isValid() const;
  bool		isPostFix() const;
  void		setPostFix();
  TokenList*	toPostfix();
  int		evalPostfix();
 private:
  Token*	head;
  Token*	tail;
  bool		valid;
  bool		postfix;
};

/* toPostfix */
TokenList*	toPostfix(TokenList *);

/* Control */
bool	isNum(char);
bool	isOpr(char);
bool	isToken(char);
bool	isNum(std::string);
bool	checkTokenList(const TokenList*);

/* Evaluation */
int	getNum(std::string s);
int	evalPostfix(TokenList*);

#endif
