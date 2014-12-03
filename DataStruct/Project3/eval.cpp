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

#include <sstream>
#include "tokenList.h"
#include "node.h"

int	getNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  ss >> n;
  return n;
}

//Returns the evaluation of the Binary Tree
int	evalBinaryTree(Node* root)
{
  if (!root)
    return 0;
  if (isNum(root->getValue()))
    return getNum(root->getValue());
  if (root->getValue() == "+")
    return (evalBinaryTree(root->getLeftChild())
	    + evalBinaryTree(root->getRightChild()));
  if (root->getValue() == "-")
    return (evalBinaryTree(root->getLeftChild())
	    - evalBinaryTree(root->getRightChild()));
  if (root->getValue() == "*")
    return (evalBinaryTree(root->getLeftChild())
	    * evalBinaryTree(root->getRightChild()));
  if (root->getValue() == "/")
    return (evalBinaryTree(root->getLeftChild())
	    / evalBinaryTree(root->getRightChild()));
  return 0;
}
