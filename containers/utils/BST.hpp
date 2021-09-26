/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:35 by kaye              #+#    #+#             */
/*   Updated: 2021/09/26 18:59:06 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include <memory>
#include "utils.hpp"

namespace ft {
/**
 * @class template: BST_Node
 */

	/**
	 * @brief BST_Node
	 */
	template < typename T>
	struct BST_Node {
		/* member types */
		
			typedef T	value_type;

		/* attributes */

			value_type	val;
			BST_Node	*left;
			BST_Node	*right;

		/* member function: constructor / destructor / operator=  */

			BST_Node(void) :
				val(),
				left(NULL),
				right(NULL) {}

			BST_Node(BST_Node *left = NULL, BST_Node *right = NULL) :
				val(),
				left(left),
				right(right) {}
			
			BST_Node(value_type val, BST_Node *left = NULL, BST_Node *right = NULL) :
				val(val),
				left(left),
				right(right) {}

			BST_Node(BST_Node const & src) :
				val(src.val),
				left(src.left),
				right(src.right) {}

			virtual ~BST_Node(void) {}

			BST_Node & operator=(BST_Node const & rhs) {
				if (this == &rhs) return *this;

				val = rhs.val;
				left = rhs.left;
				right = rhs.right;
				return *this;
			}

			/* member function: operator==  */
			bool operator==(BST_Node const & rhs) {
				return val == rhs.val;
			}
	};


/**
 * @class template: BST
 */

	/**
	 * @brief BST_Node
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

			BST(void) : root(NULL) {}
			
			virtual ~BST(void) { clear(_root); }

		/* member functions: utils */

			pointer	insert(value_type const & val);

			void	erase(value_type const & val);

			void	search(value_type const & val);

		private:
		/* attributes */
			
			pointer			_root;
			allocator_type	_alloc;

		/* private function */

			void clear(pointer node) {
				if (node == NULL)
					return ;
				clear(node->left);
				clear(node->right);
				_alloc.destroy(node);
				_alloc.dealloc(node, 1);
			}

			pointer	insert(value_type const & val, pointer node) {
				if (node == NULL) {
					node = _alloc.allocate(1);
					_alloc.construct(node, node_type(val, NULL, NULL));
				}
				else if (val.first < node.val.first)
					node->left = insert(val, node->left);
				else if (val.first > node.val.first)
					node->right = insert(val, node->right);
				return node;
			}
	};
}

#endif