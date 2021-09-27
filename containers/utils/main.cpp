#include "BST.hpp"

void f(void) {
	ft::BST< ft::pair<int, int> > t;

	// t.insert(ft::make_pair<int, int>(2, 20));
	// t.insert(ft::make_pair<int, int>(1, 25));
	// t.insert(ft::make_pair<int, int>(3, 30));
	// t.insert(ft::make_pair<int, int>(4, 50));

	// std::cout << t.getSize() << std::endl;

	// t.erase(ft::make_pair<int, int>(2, 20));

	// std::cout << t.getSize() << std::endl;

	std::cout << "max_size: " << t.getMax_size() << std::endl;
	std::cout << sizeof(t) << std::endl;
}

int main(void) {
	f();

	// system("leaks a.out");
	return 0; 
}