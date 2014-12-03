/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #5
# This program reads data from books.txt and dvd.txt,
# it then prompts the user for displaying the list of or and dvds
# or adding new objects to the lists.
*********************************************/

#ifndef DVD_H
#define DVD_H

#include "product.h"

class	dvd : public Product
{
 private:
  std::string	studio;
  std::string	mLead;
  std::string	fLead;

 public:
  dvd();
  dvd(std::string, std::string, std::string);
  dvd(std::string, std::string, std::string, std::string, std::string, std::string);
  void	print_info(void) const;
  friend std::ostream& operator<<(std::ostream& out, dvd const& o);
  friend std::istream& operator>>(std::istream& out, dvd &o);
};

#endif
