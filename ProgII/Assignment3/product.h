/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
*********************************************/

#ifndef PRODUCT_H
#define	PRODUCT_H

#include <iostream>
#include <string>

class	Product
{
 protected:
  int		id;
  std::string	name;
  double	price;
  int		stock;
  
 public:
  Product();
  Product(int, std::string, double, int);
  int		getId(void) const;
  std::string	getName(void) const;
  double	getPrice(void) const;
  int		getStock(void) const;
  void		setId(int);
  void		setName(std::string);
  void		setPrice(double);
  void		setStock(int);
  void		print_info(void) const;
  friend std::ostream& operator<<(std::ostream& out, Product const& p);
  friend std::istream& operator>>(std::istream& out, Product &p);
};

#endif
