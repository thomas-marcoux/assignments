#include "product.h"
#include "dvd.h"
#include "book.h"
#include <vector>
#include <fstream>
using namespace std;

// Following are the declarations of read_books() and read_dvds() functions that you need to complete.
void read_books(string book_file_name, vector<book> &my_books);
void read_dvds(string dvd_file_name, vector<dvd> &my_dvds);

int product::idcount = 0;
int product::num_products = 0;

int main()
{
	vector<book> all_books;
	vector<dvd> all_dvds;

	read_books("books.txt", all_books);
	read_dvds("dvds.txt", all_dvds);

	cout << "# of all instances: " << product::get_num_products() << endl;

	
	for(int i = 0; i < all_books.size(); i++)
	{
		all_books[i].print_info();
	}

	for(int i = 0; i < all_dvds.size(); i++)
	{
		all_dvds[i].print_info();
	}
	
	return 0;
}

// You can define read_books() and read_dvds() functions here