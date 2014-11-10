/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
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
  dvd(int, std::string, double, int);
  dvd(int, std::string, double, int, std::string, std::string, std::string);
  void	print_info(void) const;
};

#endif
