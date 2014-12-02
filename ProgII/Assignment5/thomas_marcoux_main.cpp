/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
*********************************************/

#include "product.h"
#include "dvd.h"
#include "book.h"
#include <vector>
#include <fstream>

std::ostream&	operator<<(std::ostream& out, Product const& p)
{
  out << "Id: " << p.id << std::endl
      << "Name: " << p.name << std::endl
      << "Price: $" << p.price << std::endl
      << "# in stock: " << p.stock << std::endl;
  return out;
}

std::istream&	operator>>(std::istream& in, Product &p)
{
  std::cout << "Id: ";
  in >> p.id;
  std::cout << "Name: ";
  in >> p.name;
  std::cout << "Price: ";
  in >> p.price;
  std::cout << "Stock: ";
  in >> p.stock;
  return in;
}

void	read_books(std::string book_file_name, std::vector<book*> &my_books)
{
  std::ifstream	in(book_file_name.c_str());
  std::string	name, price, stock, publisher, author, isbn;

  if (!in.is_open())
    return;
  while (in >> name >> price >> stock >> publisher >> author >> isbn)
    my_books.push_back(new book(name, price, stock, publisher, author, isbn));
}

void	read_dvds(std::string dvd_file_name, std::vector<dvd*> &my_dvds)
{
  std::ifstream	in(dvd_file_name.c_str());
  std::string	name, price, stock, studio, mLead, fLead;

  if (!in.is_open())
    return;
  while (in >> name >> price >> stock >> studio >> mLead >> fLead)
    my_dvds.push_back(new dvd(name, price, stock, studio, mLead, fLead));
}

void	write_books(std::string book_file_name, std::vector<book*> &my_books)
{
  std::ofstream	out(book_file_name.c_str());
  for (int i = 0; i < my_books.size(); ++i)
    out << *my_books[i];
}

void	write_dvds(std::string dvd_file_name, std::vector<dvd*> &my_dvds)
{
  std::ofstream	out(dvd_file_name.c_str());
  for (int i = 0; i < my_dvds.size(); ++i)
    out << *my_dvds[i];
}

void	add_book(std::vector<book*> &my_books)
{

}

void	add_dvd(std::vector<dvd*> &my_dvds)
{

}

template<class T>
void	print_product_vector(std::vector<T*> my_products)
{

}

int	main()
{
  std::vector<book*>	all_books;
  std::vector<dvd*>	all_dvds;
  std::string		book_file_name = "books.txt";
  std::string		dvd_file_name = "dvds.txt";

  read_books(book_file_name, all_books);
  read_dvds(dvd_file_name, all_dvds);
  write_books(book_file_name, all_books);
  write_dvds(dvd_file_name, all_dvds);
  for(int i = 0; i < all_books.size(); i++)
    delete all_books[i];
  for(int i = 0; i < all_dvds.size(); i++)
    delete all_dvds[i];
  return 0;
}
