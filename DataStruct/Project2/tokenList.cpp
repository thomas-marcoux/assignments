/* CPSC2380 
 * Department of Computer Science, UALR 
 * Project 2 
 * Student Name: Thomas Marcoux
 * Student UALR ID (last four digits): 5564
 * Project Descriptions: 
 * This project takes an arithmetic expression as input,
 * converts it to postfix and evaluates it, outputting the result.
 * Project Due Date: 11/4/2014 
 * Project Revised Date: 8/30/2014, 11/3/2014 
 */

#include <iostream>
#include <sstream>
#include <stack>
#include "tokenList.h"

TokenList::TokenList()
  : head(NULL), tail(NULL) {}

TokenList::TokenList(std::string& s)
  : head(NULL), tail(NULL)
{
  this->parseInput(s);
}

TokenList::~TokenList()
{
  Token	*buff, *it = head;

  while (it)
    {
      buff = it->getNext();
      delete it;
      it = buff;
    }
}

void	TokenList::parseInput(std::string& s)
{
  std::istringstream	ss(s);
  std::string	buff;

  while (!ss.eof())
    {
      getline(ss, buff, DELIMITER);
      this->addToken(buff);
    }
}

void	TokenList::addToken(Token *t)
{
  if (tail)
    tail->addToken(t);
  else
    head = t;
  tail = t;
}

void	TokenList::addToken(const char *s)
{
  Token	*n = new Token(std::string(s));
  this->addToken(n);    
}

void	TokenList::addToken(std::string s)
{
  Token	*n = new Token(s);
  this->addToken(n);    
}

void	TokenList::pushFront(std::string s)
{
  Token	*n = new Token(s);
  this->head = n;
}

Token*	TokenList::getHead() const
{
  return this->head;
}

void	TokenList::print() const
{
  for (Token *it = head; it; it = it->getNext())
    it->print();
  std::cout << std::endl;
}

bool	isNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  if ((ss >> n).fail())
    return false;
  return true;
}

int	getNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  ss >> n;
  return n;
}

bool	checkOperand(std::string top, std::string tk)
{
  if (top == "*" || top == "/")
    return true;
  if ((top == "+" || top == "-")
      && (tk == "+" || tk == "-"))
    return true;
  return false;
}

void	popParenthese(std::stack<std::string> &stk, TokenList *postfix)
{
  for (;!stk.empty() && stk.top() != "("; stk.pop())
    postfix->addToken(stk.top());
  stk.pop();
}

void	popOperands(std::stack<std::string> &stk, TokenList *postfix,
		    std::string item, Token* it)
{
  for (;!stk.empty() && checkOperand(stk.top(), item); stk.pop())
    postfix->addToken(stk.top());
  if (it)
    stk.push(item);
}

TokenList*	TokenList::toPostfix()
{
  TokenList	*postfix = new TokenList();
  std::stack<std::string>	stk;
  std::string	item = "";

  stk.push(std::string("("));
  this->addToken(std::string(")"));
  for (Token* it = this->getHead(); !stk.empty();)
    {
      if (it)
	item = it->getItem();
      if (item == "(")
	stk.push(item);
      else if (isNum(item))
	postfix->addToken(item);
      else if (item == ")")
	popParenthese(stk, postfix);
      else
	popOperands(stk, postfix, item, it);
      if (it)
	it = it->getNext();
    }
  return postfix;
}

int	eval(char opt, std::stack<int> &stk)
{
  int	n1;
  int	n2;

  n2 = stk.top();
  stk.pop();
  n1 = stk.top();
  stk.pop();
  if (opt == '+')
    stk.push(n1 + n2);
  else if (opt == '-')
    stk.push(n1 - n2);
  else if (opt == '*')
    stk.push(n1 * n2);
  else if (opt == '/')
    stk.push(n1 / n2);
  else
    return 0;
  return 1;
}

int	TokenList::evalPostfix()
{
  std::string	item;
  std::stack<int>	stk;
  char	c;
  int	n;

  for (Token *it = this->head; it; it = it->getNext())
    {
      item = it->getItem();
      if (isNum(item))
	{
	  n = getNum(item);
	  c = '$';
	}
      else
	c = item[0];
      switch (c)
	{
	case '$':
	  stk.push(n);
	  break;
	default:
	  if (!eval(c, stk))
	    return 0;
	}
    }
  return stk.top();
}
