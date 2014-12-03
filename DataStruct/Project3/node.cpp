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

#include <iostream>
#include <iomanip>
#include <stack>
#include "node.h"

Node::Node(std::string value)
  : value(value), leftChild(NULL), rightChild(NULL) {}

Node::Node(std::string value, Node* leftChild, Node* rightChild)
  : value(value), leftChild(leftChild), rightChild(rightChild) {}

Node::~Node()
{
  delete this->leftChild;
  delete this->rightChild;
}

std::string	Node::getValue() const
{
  return this->value;
}

Node*	Node::getLeftChild() const
{
  return this->leftChild;
}

Node*	Node::getRightChild() const
{
  return this->rightChild;
}

void	Node::setLeftChild(Node* leftChild)
{
  this->leftChild = leftChild;
}

void	Node::setRightChild(Node* rightChild)
{
  this->rightChild = rightChild;
}

void	Node::printTree(int w) const
{
  if (!this)
    return;
  Node*	l = this->getLeftChild();
  Node*	r = this->getRightChild();

  std::cout << std::setw(w);
  std::cout << this->getValue();
  if (l || r)
    std::cout << ":";
  std::cout << std::endl;
  w += 2;
  l->printTree(w);
  r->printTree(w);
}

void	Node::printInfix() const
{
  if (!this)
    return;
  Node*	l = this->getLeftChild();
  Node*	r = this->getRightChild();

  l->printInfix();
  std::cout << this->getValue() << " ";
  r->printInfix();
}

void	Node::printPostfix() const
{
  if (!this)
    return;
  Node*	l = this->getLeftChild();
  Node*	r = this->getRightChild();

  l->printPostfix();
  r->printPostfix();
  std::cout << this->getValue() << " ";
}

void	Node::printPrefix()
{
  std::stack<Node*>	stk;
  Node*			node = this;

  while (!stk.empty() || node)
    {
      if (node)
	{
	  std::cout << node->getValue() << " ";
	  if (node->getRightChild())
	    stk.push(node->getRightChild());
	  node = node->getLeftChild();
	}
      else
	{
	  node = stk.top();
	  stk.pop();
	}
    }
}
