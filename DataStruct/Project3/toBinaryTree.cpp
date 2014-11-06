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

Node*	toBinaryTree(TokenList* tl)
{
  Node*	root = NULL;
  Node*	buff = NULL;
  std::string	item;
  std::stack<std::string>	opdStack;
  std::stack<Node*>		optStack;

  if (!tl->isValid() || !tl->isPostFix())
    return NULL;
  for (Token* it = tl->getHead(); it; it->getNext())
    {
      item = it->getItem();
      if (isNum(item))
	opdStack.push(item);
      else
	{
	  buff = new Node(item);
	  buff->setLeftChild(new Node(opdStack.top()));
	  opdStack.pop();
	  buff->setRightChild(new Node(opdStack.top()));
	  opdStack.pop();
	  if (!root)
	    root = buff;
	}
    }
  return root;
}
