/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
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
  dvd(std::string, std::string, std::string,
      std::string, std::string, std::string);
  void	print_info(void) const;
};

#endif
