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

#include <stack>
#include "tokenList.h"
#include "node.h"

//Sets the two children of the Node buff from the stack stk
void	setChildren(Node* buff, std::stack<Node*> &stk)
{
  buff->setRightChild(stk.top());
  stk.pop();
  buff->setLeftChild(stk.top());
  stk.pop();
}

//Returns the root of a binary tree given a postfix expression
Node*	toBinaryTree(TokenList* tl)
{
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
	setChildren(buff, stk);
      stk.push(buff);
    }
  return stk.top();
}
