#include "BST.hpp"

void f(void) {
	using namespace std;
	
	ft::BST< ft::pair<int, int> > t;

	t.insert(ft::make_pair<int, int>(2, 20));
	t.insert(ft::make_pair<int, int>(1, 25));
	t.insert(ft::make_pair<int, int>(3, 30));
	t.insert(ft::make_pair<int, int>(4, 50));

	// t.erase(ft::make_pair<int, int>(2, 20));
	// t.erase(ft::make_pair<int, int>(3, 30));
	// t.erase(ft::make_pair<int, int>(4, 50));

	// cout << t._root->val.first << endl;
	// t.preOrderPrint();
	// cout << "\n";

	// std::cout << t.getSize() << std::endl;

	// t.erase(ft::make_pair<int, int>(2, 20));

	// std::cout << t.getSize() << std::endl;

	// t.erase(ft::make_pair<int, int>(2, 20));

	// std::cout << "max_size: " << t.getMax_size() << std::endl;
	// std::cout << sizeof(t) << std::endl;

	// cout << "val first: "<< t._node->val.first << endl;
	// cout << "val second: "<< t._node->val.second << endl;

	ft::BST< ft::pair<int, int> >::iterator it;

	it = t.min();

	// cout << t.min()->parent->val.first << endl;

	// it--;
	// it++;

	// cout << it->first << endl;

	it++;
	// it--;
	it++;
	it++;
	// it--;
	// it++;
	// it--;

	// cout << t._root->val.first << endl;

	// it++;
	// it++;
	// it--;

	cout << it->first << endl;



	// t._node = t.predecessor(t._node);

	// cout << "val first: "<< t._node->val.first << endl;
	// cout << "val second: "<< t._node->val.second << endl;

	// ft::BST< ft::pair<int, int> > t2(t);

	// cout << "\ncopy\n";

	// cout << "val first: "<< t2._node->val.first << endl;
	// cout << "val second: "<< t2._node->val.second << endl;

	// t2._node = t2.predecessor(t2._node);

	// cout << "\naft succ\n" << endl;

	// cout << "val first: "<< t2._node->val.first << endl;
	// cout << "val second: "<< t2._node->val.second << endl;

}

int main(void) {
	f();

	// system("leaks a.out");
	return 0; 
}

// #include <iostream>
// #include "BST.hpp"
// using namespace std;
 
// static ft::pair<int, int> a = ft::make_pair(1, 1);
// static ft::pair<int, int> b = ft::make_pair(5, 5);
// static ft::pair<int, int> c = ft::make_pair(4, 4);
// static ft::pair<int, int> d = ft::make_pair(3, 3);
// static ft::pair<int, int> e = ft::make_pair(2, 2);
// static ft::pair<int, int> f = ft::make_pair(6, 6);
 
// int main()
// {
// 	ft::BST< ft::pair<int, int> > tree;

// 	// cout << "== 依次添加: ";
// 	// tree.insert(ft::make_pair<int, int>(1, 1));
// 	tree.insert(a);
// 	tree.insert(b);
// 	tree.insert(c);
// 	tree.insert(d);
// 	tree.insert(e);
// 	tree.insert(f);

// 	cout << "== 最小值: " << tree.max()->val.second << endl;
// 	cout << "== 最大值: " << tree.min()->val.second << endl;
// 	cout << "== 树的详细信息: " << endl;
// 	tree.inOrderPrint();
// 	cout << "\n";

// 	cout << "\n== 删除根节点: ";
// 	cout << "4 - 4" << endl;
// 	tree.erase(ft::make_pair(4, 4));

// 	cout << "\n== 中序遍历: ";
// 	tree.inOrderPrint();
// 	cout << endl;

// 	cout << "\n== 中序遍历: ";
// 	tree.search(ft::make_pair(4, 4));
// 	cout << endl;

// 	// 销毁二叉树

// 	return 0;
// }