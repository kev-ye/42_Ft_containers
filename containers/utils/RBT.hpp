/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:35 by kaye              #+#    #+#             */
/*   Updated: 2021/10/04 19:25:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include <memory>
#include "utils.hpp"
#include "mapIte.hpp"

#include <iostream> // debug

_BEGIN_NS_FT

#define RED_NODE	1
#define BLACK_NODE 0

/**
 * @brief class declare
 */
	template < class T >
	class mapIterator;

/**
 * @class template: RBT_Node
 */

	/**
	 * @brief Red Black Tree Node
	 */
	template < class T >
	struct RBT_Node {
		/* member types */
		
			typedef T		value_type;
			typedef size_t	size_type;

		/* attributes */

			value_type	val;
			size_type	color;
			RBT_Node	*parent;
			RBT_Node	*left;
			RBT_Node	*right;
			

		/* member function: constructor / destructor / operator=  */

			RBT_Node(void) :
				val(),
				color(BLACK_NODE),
				parent(ft_nullptr),
				left(ft_nullptr),
				right(ft_nullptr) {}

			RBT_Node(size_type color = BLACK_NODE,
				RBT_Node *parent = ft_nullptr,
				RBT_Node *left = ft_nullptr,
				RBT_Node *right = ft_nullptr) :
					val(),
					color(color),
					parent(parent),
					left(left),
					right(right) {}
			
			RBT_Node(value_type val,
				size_type color = BLACK_NODE,
				RBT_Node *parent = ft_nullptr,
				RBT_Node *left = ft_nullptr,
				RBT_Node *right = ft_nullptr) :
					val(val),
					color(color),
					parent(parent),
					left(left),
					right(right) {}

			RBT_Node(RBT_Node const & src) :
				val(src.val),
				color(src.color),
				parent(src.parent),
				left(src.left),
				right(src.right) {}

			virtual ~RBT_Node(void) {}

			RBT_Node & operator=(RBT_Node const & rhs) {
				if (this == &rhs) return *this;

				val = rhs.val;
				color = rhs.color;
				parent = rhs.parent;
				left = rhs.left;
				right = rhs.right;
				return *this;
			}

			/* member function: operator==  */
			bool operator==(RBT_Node const & rhs) {
				if (val == rhs.val)
					return true;
				return false;
			}
	};

/**
 * @class template: RBT
 */

	/**
	 * @brief Red Black Tree
	 */
	template < class T,
		// class Compare = ft::less<T>,
		class Node = ft::RBT_Node<T>,
		class AllocNode = std::allocator<Node> >
	class RBT {
		public:
		/* member types */

			typedef				T			value_type;
			typedef				Node		node_type;

			typedef				AllocNode								allocator_type;
			typedef	typename	allocator_type::reference				reference;
			typedef	typename	allocator_type::const_reference			const_reference;
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;

			/** @note usually the same as ptrdiff_t */
			typedef	typename	allocator_type::difference_type			difference_type;
			/** @note usually the same as size_t */
			typedef	typename	allocator_type::size_type				size_type;

			typedef				ft::mapIterator<Node>					iterator;

		public:
			RBT(allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
				_null = _alloc.allocate(1);
				_alloc.construct(_null, node_type(BLACK_NODE, ft_nullptr, ft_nullptr, ft_nullptr)); // null node is a black node
				_root = _null;
			}

			virtual ~RBT() {}
			
			// Pre-Order traversal
			// node->Left Subtree->Right Subtree
			void	preorder() {
				preOrderHelper(_root);
				std::cout << std::endl;
			}

			// In-Order traversal
			// Left Subtree -> node -> Right Subtree
			void	inorder() {
				inOrderHelper(_root);
				std::cout << std::endl;
			}

			// Post-Order traversal
			// Left Subtree -> Right Subtree -> node
			void	postorder() {
				postOrderHelper(_root);
				std::cout << std::endl;
			}

			pointer	min() {
				return min(_root);
			}

			pointer	max() {
				return max(_root);
			}

			// search the tree for the key key
			// and return the corresponding node
			pointer	searchTree(value_type key) {
				return searchTreeHelper(_root, key);
			}

			// find the successor of a given node
			pointer	successor(pointer x) {
				// if the right subtree is not null,
				// the successor is the leftmost node in the
				// right subtree
				if (x->right != _null)
					return min(x->right);

				// else it is the lowest ancestor of x whose
				// left child is also an ancestor of x.
				pointer y = x->parent;
				while (y != _null && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			// find the predecessor of a given node
			pointer	predecessor(pointer s) {
				// if the left subtree is not null,
				// the predecessor is the rightmost node in the 
				// left subtree
				if (s->left != _null)
					return max(s->left);

				pointer	tmp = s->parent;
				while (tmp != _null && s == tmp->left) {
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			// insert the key to the tree in its appropriate position
			// and fix the tree
			ft::pair<iterator, bool>	insert(value_type const & key) {
				// Ordinary Binary Search Insertion
				pointer s = _alloc.allocate(1);
				_alloc.construct(s, node_type(key, RED_NODE, ft_nullptr, _null, _null)); // new node must be red

				pointer y = ft_nullptr;
				pointer x = _root;

				while (x != _null) {
					y = x;
					if (s->val.first < x->val.first)
						x = x->left;
					else if (s->val.first > x->val.first)
						x = x->right;
					else {
						_alloc.destroy(s);
						_alloc.deallocate(s, 1);
						return ft::make_pair<iterator, bool>(iterator(getRoot(), y, getNull()), false);
					}
				}

				// y is parent of x
				s->parent = y;
				if (y == ft_nullptr)
					_root = s;
				else if (s->val.first < y->val.first)
					y->left = s;
				else
					y->right = s;

				// if new node is a _root node, simply return
				if (s->parent == ft_nullptr) {
					s->color = BLACK_NODE;
					return ft::make_pair<iterator, bool>(iterator(getRoot(), y, getNull()), true);
				}

				// if the grandparent is null, simply return
				if (s->parent->parent == ft_nullptr)
					return ft::make_pair<iterator, bool>(iterator(getRoot(), y, getNull()), true);

				// Fix the tree
				fixInsert(s);
				return ft::make_pair<iterator, bool>(iterator(getRoot(), y, getNull()), true);
			}

			pointer	getRoot() {
				return _root;
			}

			pointer	getNull() {
				return _null;
			}

			// delete the node from the tree
			void	deleteNode(value_type const & key) {
				deleteNodeHelper(_root, key);
			}

			void	destroyTree() {
				destroyTree(_root);

				_alloc.destroy(_null);
				_alloc.deallocate(_null, 1);
			}

			// print the tree structure on the screen
			void	prettyPrint() {
				if (_root)
					printHelper(_root, "", true);
			}

		private:

			void	preOrderHelper(pointer node) {
				if (node != _null) {
					std::cout << node->val.first << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				} 
			}

			void	inOrderHelper(pointer node) {
				if (node != _null) {
					inOrderHelper(node->left);
					std::cout << node->val.first << " ";
					inOrderHelper(node->right);
				} 
			}

			void	postOrderHelper(pointer node) {
				if (node != _null) {
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout << node->val.first << " ";
				} 
			}

			// find the node with the minimum key
			pointer	min(pointer s) {
				while (s->left != _null)
					s = s->left;
				return s;
			}

			// find the node with the maximum key
			pointer	max(pointer s) {
				while (s->right != _null)
					s = s->right;
				return s;
			}

			pointer	searchTreeHelper(pointer node, value_type const & key) {
				if (node == _null || key.first == node->val.first)
					return node;
				if (key.first < node->val.first)
					return searchTreeHelper(node->left, key);
				return searchTreeHelper(node->right, key);
			}

			// rotate left at node x
			void	leftRotate(pointer s) {
				pointer	tmp = s->right;
				
				s->right = tmp->left;
				if (tmp->left != _null)
					tmp->left->parent = s;
				tmp->parent = s->parent;
				if (s->parent == ft_nullptr)
					_root = tmp;
				else if (s == s->parent->left)
					s->parent->left = tmp;
				else
					s->parent->right = tmp;
				tmp->left = s;
				s->parent = tmp;
			}

			// rotate right at node x
			void	rightRotate(pointer x) {
				pointer	y = x->left;
				
				x->left = y->right;
				if (y->right != _null)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == ft_nullptr)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			// fix the red-black tree
			void	fixInsert(pointer k) {
				pointer	u;
				
				while (k->parent->color == RED_NODE) {
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left; // uncle
						if (u->color == RED_NODE) {
							// case 3.1
							u->color = BLACK_NODE;
							k->parent->color = BLACK_NODE;
							k->parent->parent->color = RED_NODE;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->left) {
								// case 3.2.2
								k = k->parent;
								rightRotate(k);
							}
							// case 3.2.1
							k->parent->color = BLACK_NODE;
							k->parent->parent->color = RED_NODE;
							leftRotate(k->parent->parent);
						}
					}
					else {
						u = k->parent->parent->right; // uncle

						if (u->color == RED_NODE) {
							// mirror case 3.1
							u->color = BLACK_NODE;
							k->parent->color = BLACK_NODE;
							k->parent->parent->color = RED_NODE;
							k = k->parent->parent;	
						}
						else {
							if (k == k->parent->right) {
								// mirror case 3.2.2
								k = k->parent;
								leftRotate(k);
							}
							// mirror case 3.2.1
							k->parent->color = BLACK_NODE;
							k->parent->parent->color = RED_NODE;
							rightRotate(k->parent->parent);
						}
					}
					if (k == _root)
						break ;
				}
				_root->color = BLACK_NODE;
			}

			// fix the rb tree modified by the delete operation
			void	fixDelete(pointer x) {
				pointer	s;
				while (x != _root && x->color == BLACK_NODE) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == RED_NODE) {
							// case 3.1
							s->color = BLACK_NODE;
							x->parent->color = RED_NODE;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == BLACK_NODE && s->right->color == BLACK_NODE) {
							// case 3.2
							s->color = RED_NODE;
							x = x->parent;
						}
						else {
							if (s->right->color == BLACK_NODE) {
								// case 3.3
								s->left->color = BLACK_NODE;
								s->color = RED_NODE;
								rightRotate(s);
								s = x->parent->right;
							} 

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK_NODE;
							s->right->color = BLACK_NODE;
							leftRotate(x->parent);
							x = _root;
						}
					}
					else {
						s = x->parent->left;
						if (s->color == RED_NODE) {
							// case 3.1
							s->color = BLACK_NODE;
							x->parent->color = RED_NODE;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->left->color == BLACK_NODE && s->right->color == BLACK_NODE) {
							// case 3.2
							s->color = RED_NODE;
							x = x->parent;
						}
						else {
							if (s->left->color == BLACK_NODE) {
								// case 3.3
								s->right->color = BLACK_NODE;
								s->color = RED_NODE;
								leftRotate(s);
								s = x->parent->left;
							} 

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK_NODE;
							s->left->color = BLACK_NODE;
							rightRotate(x->parent);
							x = _root;
						}
					} 
				}
				x->color = BLACK_NODE;
			}


			void	rbTransplant(pointer u, pointer v) {
				if (u->parent == ft_nullptr)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void	deleteNodeHelper(pointer node, value_type const & key) {
				// find the node containing key
				pointer z = _null;
				pointer x;
				pointer y;

				while (node != _null) {
					if (node->val.first == key.first) {
						z = node;
					}

					if (node->val.first <= key.first) {
						node = node->right;
					}
					else {
						node = node->left;
					}
				}

				if (z == _null) {
					std::cout << "Couldn't find key in the tree" << std::endl;
					return ;
				} 

				y = z;
				int y_original_color = y->color;
				if (z->left == _null) {
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == _null) {
					x = z->left;
					rbTransplant(z, z->left);
				}
				else {
					y = min(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
					}
					else {
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}

				// delete z;
				_alloc.destroy(z);
				_alloc.deallocate(z, 1);

				if (y_original_color == BLACK_NODE)
					fixDelete(x);
			}

			void	printHelper(pointer root, std::string indent, bool last) {
				// print the tree structure on the screen
				if (root != _null) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "     ";
					}
					else {
						std::cout << "L----";
						indent += "|    ";
					}
					
					std::string	sColor = root->color ? "RED" : "BLACK";
					std::cout << root->val.first << "(" << sColor << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
				// std::cout << root->left->val << std::endl;
			}

			void destroyTree(pointer root) {
				if (root == _null) {
					return ;
				}

				destroyTree(root->left);
				destroyTree(root->right);

				_alloc.destroy(root);
				_alloc.deallocate(root, 1);
			}

		private:
			pointer			_root;
			pointer			_null;
			allocator_type	_alloc;
	};

_END_NS_FT

#endif