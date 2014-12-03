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
#include "tokenList.h"
#include "node.h"

Node*	toBinaryTree(TokenList* tl);
int	evalBinaryTree(Node* root);

int	main()
{
  TokenList	*postFix;
  Node		*root;
  std::string	input;

  while(1)
    {
      input = "";
      std::cout << "? ";
      std::cin >> input;
      if (input == "" || input == "quit" || input == "exit")
	return 1;
      TokenList	l = TokenList(input);
      postFix = toPostfix(&l);
      if (postFix)
	{
	  root = toBinaryTree(postFix);
	  std::cout << "Tree: " << std::endl;
	  root->printTree();
	  std::cout << "Infix: ";
	  root->printInfix();
	  std::cout << std::endl << "Postfix: ";
	  root->printPostfix();
	  std::cout << std::endl << "Prefix: ";
	  root->printPrefix();
	  std::cout << std::endl << "Result = " << evalBinaryTree(root) << std::endl;
	  delete postFix;
	  delete root;
	}
    }
  return 1;
}
