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
  std::string	isbn;

 public:
  book();
  book(std::string, std::string, std::string);
  book(std::string, std::string, std::string,
       std::string, std::string, std::string);
  void	print_info(void) const;
};

#endif
