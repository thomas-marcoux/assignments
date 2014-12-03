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
