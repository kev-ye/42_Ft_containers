/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:35 by kaye              #+#    #+#             */
/*   Updated: 2021/10/01 13:44:43 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include <memory>
#include "utils.hpp"
#include "mapIte.hpp"

#include <iostream> // debug

namespace ft {
/**
 * @brief class declare
 */
	template < class T >
	class mapIterator;

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

			typedef				ft::mapIterator<Node>					iterator;

		public:
		/* member functions: constructor / destructor */

			BST(allocator_type const & alloc = allocator_type()) :
				_root(NULL),
				_alloc(alloc) {}
			
			virtual ~BST(void) { destroy(); }

		/* member functions: capacity */

			size_type		getSize(void) const {
				return size(_root);
			}

			difference_type		getMax_size(void) const {
				return _alloc.max_size();
			}

		/* member functions: finder */

			pointer	max(void) const {
				pointer node = max(_root);
				if (node != NULL)
					return node;
				return NULL;
			}

			pointer	min(void) const {
				pointer node = min(_root);
				if (node != NULL)
					return node;
				return NULL;
			}

			void	search(value_type const & val) {
				_root = search(val, _root);
			}

		/* member functions: predecessor / successor */

			// pointer	predecessor(pointer node) {
			// 	if (node->left != NULL)
			// 		return max(node->left);
				
			// 	pointer pre = node->parent;
			// 	while (pre != NULL && node == pre->left) {
			// 		node = pre;
			// 		pre = pre->parent;
			// 	}
			// 	return pre;
			// }

			pointer	successor(pointer node) {
				if (node->right != NULL)
					return min(node->right);
				
				pointer succ = node->parent;
				while (succ != NULL && node == succ->right) {
					node = succ;
					succ = succ->parent;
				}
				return succ;
			}

		/* member functions: modifiers */

			void	insert(value_type const & val) {
				pointer toInsert = _alloc.allocate(1);
				_alloc.construct(toInsert, node_type(val, NULL, NULL, NULL));

				// the second param is a reference.
				insert(toInsert, _root);
			}

			void	erase(value_type const & val) {
				pointer	toErase = search(val, _root);
				pointer node = NULL;

				if (toErase != NULL)
					node = erase(toErase, _root);

				if (node != NULL) {
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					node = NULL;
				}
			}

			void	destroy(void) {
				destroy(_root);
				_root = NULL;
			}

		/* member functions: other */
		
			void inOrderPrint(void) {
				inOrderPrint(_root);
			}

			void preOrderPrint(void) {
				preOrderPrint(_root);
			}

		/* public attributes */

			pointer			_root;

		private:
		/* private attributes */
			
			allocator_type	_alloc;

		/* private functions: capacity */

			size_type size(pointer node) const {
				if (node == NULL)
					return 0;
				else
					return size(node->left) + 1 + size(node->right);
			}

		/* private functions: finder */

			pointer max(pointer node) const {
				if(node == NULL)
					return NULL;

				while (node->right != NULL)
					node = node->right;
				return node;
			}

			pointer min(pointer node) const {
				if(node == NULL)
					return NULL;

				while (node->left != NULL)
					node = node->left;
				return node;
			}

			pointer search(value_type const & val, pointer node) const {
				if(node == NULL)
					return node;
				else if(val.first < node->val.first)
					return search(val, node->left);
				else if(val.first > node->val.first)
					return search(val, node->right);
				else
					return node;
			}

			// pointer search(value_type const & val, pointer node) const { // iterative
			// 	while (node != NULL && node->val.first != val.first) {
			// 		if (val.first < node->val.first)
			// 			node = node->left;
			// 		else
			// 			node = node->right;
			// 	}
			// 	return node;
			// }

		/* private functions: modifiers */

			void destroy(pointer &node) {
				if (node == NULL)
					return ;

				if (node->left != NULL)
					return destroy(node->left);
				if (node->right != NULL)
					return destroy(node->right);
	
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				node = NULL;
			}

			pointer	insert(pointer toInsert, pointer &node) {
				pointer currentNode = NULL;
				pointer tmpNode = node;

				while (tmpNode != NULL) {
					currentNode = tmpNode;
					if (toInsert->val.first < tmpNode->val.first)
						tmpNode = tmpNode->left;
					else if (toInsert->val.first > tmpNode->val.first)
						tmpNode = tmpNode->right;
					else {
						_alloc.destroy(toInsert);
						_alloc.deallocate(toInsert, 1);
						toInsert = NULL;
						return  node;
					}
				}

				toInsert->parent = currentNode;
				if (currentNode == NULL) {
					node = toInsert;
					// node->parent = toInsert;
				}
				else if (toInsert->val.first < currentNode->val.first)
					currentNode->left = toInsert;
				else
					currentNode->right = toInsert;
				return node;
			}

			pointer erase(pointer toErase, pointer &node) {
				pointer replaceNode = NULL;
				pointer nodeToErase = NULL;

				// get the node to delete.
				if (toErase->left == NULL || toErase->right == NULL)
					nodeToErase = toErase;
				else
					nodeToErase = successor(toErase);
				
				// save the replace node.
				if (nodeToErase->left != NULL)
					replaceNode = nodeToErase->left;
				else
					replaceNode = nodeToErase->right;

				// save the parent node if replace is not a NULL node.
				if (replaceNode != NULL)
					replaceNode->parent = nodeToErase->parent;

				// replace node.
				if (nodeToErase->parent == NULL)
					node = replaceNode;
				else if (nodeToErase == nodeToErase->parent->left)
					nodeToErase->parent->left = replaceNode;
				else
					nodeToErase->parent->right = replaceNode;

				// save value if node does not match param node.
				if (nodeToErase != toErase)
					toErase->val = nodeToErase->val;
				return nodeToErase;
			}

		/* private functions: others */

			void inOrderPrint(pointer node) {
				if(node == NULL)
					return ;
				inOrderPrint(node->left);
				std::cout << node->val.first << " ";
				inOrderPrint(node->right);
			}

			void preOrderPrint(pointer node) {
				if(node == NULL)
					return ;
				std::cout << node->val.first << " ";
				inOrderPrint(node->left);
				inOrderPrint(node->right);
			}
	};

	
}

#endif