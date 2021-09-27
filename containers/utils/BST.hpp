/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:35 by kaye              #+#    #+#             */
/*   Updated: 2021/09/27 20:53:12 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include <memory>
#include "utils.hpp"

#include <iostream> // debug

namespace ft {
/**
 * @class template: BST_Node
 */

	/**
	 * @brief binary search tree node
	 */
	template < class T >
	struct BST_Node {
		/* member types */
		
			typedef T	value_type;

		/* attributes */

			value_type	val;
			BST_Node	*parent;
			BST_Node	*left;
			BST_Node	*right;

		/* member function: constructor / destructor / operator=  */

			BST_Node(void) :
				val(),
				parent(NULL),
				left(NULL),
				right(NULL) {}

			BST_Node(BST_Node *parent = NULL, BST_Node *left = NULL, BST_Node *right = NULL) :
				val(),
				parent(parent),
				left(left),
				right(right) {}
			
			BST_Node(value_type val, BST_Node *parent = NULL, BST_Node *left = NULL, BST_Node *right = NULL) :
				val(val),
				parent(parent),
				left(left),
				right(right) {}

			BST_Node(BST_Node const & src) :
				val(src.val),
				parent(src.parent),
				left(src.left),
				right(src.right) {}

			virtual ~BST_Node(void) {}

			BST_Node & operator=(BST_Node const & rhs) {
				if (this == &rhs) return *this;

				val = rhs.val;
				parent = rhs.parent;
				left = rhs.left;
				right = rhs.right;
				return *this;
			}

			/* member function: operator==  */
			bool operator==(BST_Node const & rhs) {
				if (val == rhs.val)
					return true;
				else
					return false;
			}
	};

/**
 * @class template: BST
 */

	/**
	 * @brief Binary search tree
	 */
	template < class T,
		// class Compare = ft::less<T>,
		class Node = ft::BST_Node<T>,
		class AllocNode = std::allocator<Node> >
	class BST {
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

		public:
		/* member functions: constructor / destructor / operator= */

			BST(allocator_type const & alloc = allocator_type()) :
			_root(NULL),
			_alloc(alloc) {}

			BST(BST const & src) : _root(NULL) {
				preOrderDeepCopy(src._root);
			}
			
			virtual ~BST(void) { clear(_root); }

			BST & operator=(BST const & rhs) {
				if (this == &rhs) return *this;

				clear(_root);
				preOrderDeepCopy(rhs._root);
				return *this;
			}

		/* member functions: capacity */

			size_type		getSize(void) const {
				return size(_root);
			}

			difference_type		getMax_size(void) const {
				return _alloc.max_size();
			}

		/* member functions: finder */

			value_type	max(void) const {
				pointer node = max(_root);
				if (node != NULL)
					return node->val;
				return NULL;
			}

			value_type	min(void) const {
				pointer node = min(_root);
				if (node != NULL)
					return node->val;
				return NULL;
			}

			void	search(value_type const & val) {
				_root = search(val, _root);
			}

		/* member functions: predecessor / successor */

			pointer	predecessor(pointer node) {
				if (node->left != NULL)
					return max(node->left);
				
				pointer pre = node->parent;
				while (pre != NULL && node == pre->left) {
					node = pre;
					pre = pre->parent;
				}
				return pre;
			}

			pointer	successor(pointer node) {
				if (node->right != NULL)
					return min(node->right);
				
				pointer succ = node->parent;
				while (succ != NULL && node == succ->left) {
					node = succ;
					succ = succ->parent;
				}
				return succ;
			}

		/* member functions: modifiers */

			void	insert(value_type const & val) {
				_root = insert(val, _root);
			}

			void	erase(value_type const & val) {
				_root = erase(val, _root);
			}

			void	destroy(void) {}

		private:
		/* attributes */
			
			pointer			_root;
			allocator_type	_alloc;

		/* private functions: capacity */

			size_type size(pointer node) const {
				if (node == NULL)
					return 0;
				else
					return size(node->left) + 1 + size(node->right);
			}

		/* private functions: finder */

			pointer max(pointer node) {
				if(node == NULL)
					return NULL;

				while (node->right != NULL)
					node = node->right;
				return node;
			}

			pointer min(pointer node) {
				if(node == NULL)
					return NULL;

				while (node->left != NULL)
					node = node->left;
				return node;
			}

			pointer search(value_type const & val, pointer node) {
				if(node == NULL || val.first == node->val.first)
					return node;

				if(val.first < node->val.first)
					return find(val, node->left);
				else if(val.first > node->val.first)
					return find(val, node->right);
			}

		/* private functions: modifiers */

			void clear(pointer node) {
				if (node == NULL)
					return ;
				clear(node->left);
				clear(node->right);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}

			pointer	insert(value_type const & val, pointer node) {
				if (node == NULL) {
					node = _alloc.allocate(1);
					_alloc.construct(node, node_type(val, NULL, NULL));
				}
				else if (val.first < node->val.first)
					node->left = insert(val, node->left);
				else if (val.first > node->val.first)
					node->right = insert(val, node->right);
				return node;
			}

			pointer erase(value_type const & val, pointer node) {
				pointer tmp = NULL;

				if(node == NULL)
					return NULL;
				else if(val.first < node->val.first)
					node->left = erase(val, node->left);
				else if(val.first > node->val.first)
					node->right = erase(val, node->right);
				else if(node->left && node->right) {
					tmp = findMin(node->right);
					node->val = tmp->val;
					node->right = erase(node->val, node->right);
				}
				else {
					tmp = node;
					if(node->left == NULL)
						node = node->right;
					else if(node->right == NULL)
						node = node->left;
					_alloc.destroy(tmp);
					_alloc.deallocate(tmp, 1);
				}
				return node;
			}

		/* private functions: others */

			void preOrderDeepCopy(pointer src) {
				if (src == NULL)
					return ;
				_root = insert(src->val, _root);
				preOrderDeepCopy(src->left);
				preOrderDeepCopy(src->right);
			}

			void inOrderPrint(pointer node) {
				if(node == NULL)
					return ;
				inOrderPrint(node->left);
				std::cout << node->val.second << " ";
				inOrderPrint(node->right);
			}
	};

	
}

#endif