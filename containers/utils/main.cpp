#include "RBT.hpp"

void f(void) {
	using namespace std;
	
	// ft::RBT< ft::pair<int, int> > tree;

	// tree.insert(ft::make_pair<int, int>(1, 10));
	// tree.insert(ft::make_pair<int, int>(2, 20));
	// tree.insert(ft::make_pair<int, int>(3, 30));
	// tree.insert(ft::make_pair<int, int>(4, 40));
	// tree.insert(ft::make_pair<int, int>(5, 50));
	// tree.insert(ft::make_pair<int, int>(6, 60));
	// tree.insert(ft::make_pair<int, int>(7, 70));
	// tree.insert(ft::make_pair<int, int>(8, 80));
	// tree.insert(ft::make_pair<int, int>(9, 90));

	// tree.prettyPrint();
	// cout << "pre:\n";
	// tree.preorder();
	// cout << "in:\n";
	// tree.inorder();

	ft::RBT< ft::pair<int, int> > tree;
	tree.insert(ft::make_pair<int, int>(1, 10));
	tree.insert(ft::make_pair<int, int>(2, 20));
	tree.insert(ft::make_pair<int, int>(2, 20));
	tree.insert(ft::make_pair<int, int>(3, 30));
	tree.insert(ft::make_pair<int, int>(4, 40));
	tree.prettyPrint();

	// ptr
	// ft::RBT_Node< ft::pair<int, int> > *ptr = tree.getRoot();

	// cout << "\nsuccessor test:\n";
	// ptr = tree.successor(ptr);
	// ptr = tree.successor(ptr);
	// ptr = tree.successor(ptr);

	// cout << "root: " << ptr->val.first << endl;
}

#include <map>

int main(void) {
	f();

	// system("leaks a.out");
	return 0; 
}