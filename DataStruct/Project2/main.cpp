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

int	main(int argc, char **argv)
{
  TokenList	*postFix;
  if (argc > 1)
    {
      std::string	expr(argv[1]);
      TokenList	l = TokenList(expr);
      std::cout << "Infix:" << std::endl;
      l.print();      
      postFix = toPostfix(&l);
      if (postFix)
	{
	  std::cout << "Postfix:" << std::endl;
	  postFix->print();
	  std::cout << "Result = " << evalPostfix(postFix) << std::endl;
	  delete postFix;
	}
      std::cout << std::endl;
    }
  return 0;
}
