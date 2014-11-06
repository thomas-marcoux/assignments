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
#include <iomanip>
#include <stack>
#include "tokenList.h"
#include "node.h"

void	printTree(Node* root, int w = 0)
{
  if (!root)
    return;
  std::cout << std::setw(w);
  std::cout << root->getValue();
  if (root->getLeftChild() || root->getRightChild())
    std::cout << ":";
  std::cout << std::endl;
  w += 2;
  printTree(root->getLeftChild(), w);
  printTree(root->getRightChild(), w);
}

void	setChild(Node* buff, std::stack<Node*> &stk)
{
  if (!buff->getLeftChild())
    buff->setLeftChild(stk.top());
  else
    buff->setRightChild(stk.top());
  stk.pop();
}

void	setChildren(Node* buff, std::stack<Node*> &stk)
{
  if (buff->getLeftChild() && buff->getRightChild())
    return;
  if (!stk.empty())
    setChild(buff, stk);
  else
    setChild(buff, stk);
  setChildren(buff, stk);
}

Node*	toBinaryTree(TokenList* tl)
{
  Node*	root = NULL;
  Node*	buff = NULL;
  std::string	item;
  std::stack<Node*>	stk;

  if (!tl || !tl->isValid() || !tl->isPostFix())
    return NULL;
  for (Token* it = tl->getHead(); it; it = it->getNext())
    {
      item = it->getItem();
      buff = new Node(item);
      if (!isNum(item))
	{
	  setChildren(buff, stk);
	  root = buff;
	}
      stk.push(buff);
    }
  return stk.top();
}
