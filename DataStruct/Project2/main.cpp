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

int	main()
{
  std::string	s[] = {
      "1+2-4",
      "10*(2+3)",
      "10/3+2-5*(2-3)+45",
      "3-4 5",
      "(2*3)+(5-(3*2))"
  };
  TokenList	*postFix;

  for (int i = 0; i < 5; ++i)
    {
      TokenList	l = TokenList(s[i]);
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
