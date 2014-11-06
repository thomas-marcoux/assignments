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

class	book : public Product
{
 private:
  std::string	publisher;
  std::string	author;
  int		isbn;

 public:
  book();
  book(int, std::string, double, int);
  book(int, std::string, double, int, std::string, std::string, int);
  void	print_info(void) const;
};

#endif
