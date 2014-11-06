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
};

#endif
