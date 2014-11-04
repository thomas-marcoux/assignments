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

//If an input is given, evaluates the input; if not, evaluates the array s
int	main(int argc, char **argv)
{
  std::string	s[] = {
    "2+2",
    "+",
    ")",
    "(",
    "42",
    "4 2",
    "4/2",
    "(4/2",
    "4//2",
    "4/2)",
    "(4/2))",
    "4/0",
    "004*003",
    "1+2-4",
    "10*(2+3)",
    "10/3+2-(5*(2-3))+45",
    "3-4 5",
    "(2*3)+(5-(3*2))",
    "((((6/0003) + 2) * 003) - 3)",
    "6*(3+1$)"
  };
  TokenList	*postFix;
  int	n = 20;

  if (argc == 2)
    {
      n = 1;
      s[0] = argv[1];
    }
  if (argc > 2)
    {
      std::cout << "Usage: " << argv[0] << " <expression>" << std::endl;
      return 0;
    }
  for (int i = 0; i < n; ++i)
    {
      std::cout << i+1 << " : ";
      TokenList	l = TokenList(s[i]);
      postFix = toPostfix(&l);
      if (postFix)
	{
	  std::cout << s[i] << " = " << evalPostfix(postFix) << std::endl;
	  delete postFix;
	}
    }
  return 0;
}
