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
