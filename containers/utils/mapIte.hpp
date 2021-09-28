/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:31:14 by kaye              #+#    #+#             */
/*   Updated: 2021/09/28 19:56:59 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITE_HPP
# define MAPITE_HPP

#include "BST.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {
/**
 * @class template: mapIterator
 */
	
	/**
	 * @class template: mapIterator
	 * @brief bidirectional iterator
	 */
	template < class T >
	class mapIterator : public ft::iterator<bidirectional_iterator_tag, T> {
		public:
		/* member types */

			typedef typename T::value_type													value_type;

			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

			typedef T	node_type;
			typedef T*	node_pointer;
		
		public:
		/* member functions */

		/* constructor / destructor / operator= */
			
			mapIterator(void) : _node(NULL) {}
			mapIterator(node_pointer node) : _node(node) {}
			mapIterator(mapIterator const & src) : _node(src._node) {}
			virtual ~mapIterator(void) {}

			mapIterator & operator= (mapIterator const & rhs) {
				if (this == &rhs) return *this;

				this->_node = rhs._node;
				return *this;
			}
		
		/* operator */
			
			reference	operator* (void) const { return _node->val; }

			pointer		operator->(void) const { return &(operator*()); }

			/** @brief increment node position*/
			mapIterator &	operator++ (void) {
				_node = successor(_node);
				return *this;
			}
			
			mapIterator	operator++ (int) {
				node_pointer tmp = _node;
				operator++();
				return tmp;
			}

			/** @brief decrease node position*/
			mapIterator &	operator-- (void) {
				_node = predecessor(_node);
				return *this;
			}
			
			mapIterator	operator-- (int) {
				node_pointer tmp = _node;
				operator--();
				return tmp;
			}

		private:
		/** attributes */
			
			node_pointer _node;

		/** private function */

			node_pointer max(node_pointer node) const {
				if(node == NULL)
					return NULL;

				while (node->right != NULL)
					node = node->right;
				return node;
			}

			node_pointer min(node_pointer node) const {
				if(node == NULL)
					return NULL;

				while (node->left != NULL)
					node = node->left;
				return node;
			}

			node_pointer	predecessor(node_pointer node) {
				if (node->left != NULL)
					return max(node->left);
				
				node_pointer pre = node->parent;
				while (pre != NULL && node == pre->left) {
					node = pre;
					pre = pre->parent;
				}
				return pre;
			}

			node_pointer	successor(node_pointer node) {
				if (node->right != NULL)
					return min(node->right);
				
				node_pointer succ = node->parent;
				while (succ != NULL && node == succ->left) {
					node = succ;
					succ = succ->parent;
				}
				return succ;
			}
	};
}

#endif