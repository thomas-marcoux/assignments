/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #5
# This program reads data from books.txt and dvd.txt,
# it then prompts the user for displaying the list of or and dvds
# or adding new objects to the lists.
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
  book(std::string, std::string, std::string, std::string, std::string, std::string);
  void	print_info(void) const;
  friend std::ostream& operator<<(std::ostream& out, book const& o);
  friend std::istream& operator>>(std::istream& out, book &o);
};

#endif
