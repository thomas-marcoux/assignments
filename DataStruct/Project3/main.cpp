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
      std::cin >> input;
      if (input == "" || input == "quit" || input == "exit")
	return 1;
      TokenList	l = TokenList(input);
      postFix = toPostfix(&l);
      if (postFix)
	{
	  root = toBinaryTree(postFix);
	  std::cout << "Tree = " << std::endl;
	  root->printTree();
	  std::cout << "Infix = " << std::endl;
	  root->printInfix();
	  std::cout << std::endl << "Postfix = " << std::endl;
	  root->printPostfix();
	  std::cout << std::endl << "Prefix = " << std::endl;
	  root->printPrefix();
	  std::cout << std::endl << "Result = " << evalBinaryTree(root) << std::endl;
	  delete postFix;
	  delete root;
	}
    }
  return 0;
}
