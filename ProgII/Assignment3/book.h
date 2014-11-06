/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
*********************************************/

#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class	Book : public Product
{
 private:
  std::string	publisher;
  std::string	author;
  int		isbn;

 public:
  Book();
  Book(int, std::string, double, int);
  Book(int, std::string, double, int, std::string, std::string, int);
  void	print_info(void) const;
};

#endif
