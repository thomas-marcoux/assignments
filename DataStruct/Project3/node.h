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

#ifndef NODE_H
#define	NODE_H

#include <string>

class	Node
{
 private:
  std::string	value;
  Node*		leftChild;
  Node*		rightChild;

 public:
  Node(std::string);
  Node(std::string, Node*, Node*);
  ~Node();
  std::string	getValue(void) const;
  Node*	getLeftChild(void) const;
  Node*	getRightChild(void) const;
  void	setLeftChild(Node*);
  void	setRightChild(Node*);
  void	printTree(int = 0) const;
  void	printInfix(void) const;
  void	printPostfix(void) const;
  void	printPrefix(void);
};

#endif
