/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #2
# This program uses an overloaded >> operator to
# assign values to a Product instance and then prints
# the result using an overloaded << operator
*********************************************/

#ifndef PRODUCT_H
#define	PRODUCT_H

#include <iostream>
#include <string>

class	Product
{
 private:
  int		id;
  std::string	name;
  double	price;
  int		stock;
  
 public:
  Product();
  Product(int, std::string, double, int);
  int		getId() const;
  std::string	getName() const;
  double	getPrice() const;
  int		getStock() const;
  void		setId(int);
  void		setName(std::string);
  void		setPrice(double);
  void		setStock(int);
  friend std::ostream& operator<<(std::ostream& out, Product const& p);
  friend std::istream& operator>>(std::istream& out, Product &p);
};

#endif
