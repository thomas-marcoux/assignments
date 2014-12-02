/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
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
  std::string	price;
  std::string	stock;
  
 private:
  static int	nb_products;
  static int	next_id;

 public:
  Product();
  Product(std::string, std::string, std::string);
  ~Product();
  int		getId(void) const;
  std::string	getName(void) const;
  std::string	getPrice(void) const;
  std::string	getStock(void) const;
  static int	getNbProducts(void) {return nb_products;}
  void		setId(int);
  void		setName(std::string);
  void		setPrice(std::string);
  void		setStock(std::string);
  void		print_info(void) const;
  friend std::ostream& operator<<(std::ostream& out, Product const& p);
  friend std::istream& operator>>(std::istream& out, Product &p);
};

#endif
