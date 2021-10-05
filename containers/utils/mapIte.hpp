/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:31:14 by kaye              #+#    #+#             */
/*   Updated: 2021/10/05 17:28:02 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITE_HPP
# define MAPITE_HPP

#include "RBT.hpp"
#include "iterator.hpp"
#include "utils.hpp"

#include <iostream>

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

			typedef typename T::value_type																value_type;

			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

			typedef T	node_type;
			typedef T*	node_pointer;
		
		public:
		/* member functions */

		/* constructor / destructor / operator= */
			
			mapIterator(void) :
				_root(ft_nullptr),
				_node(ft_nullptr),
				_null(ft_nullptr) {}

			mapIterator(node_pointer root, node_pointer node, node_pointer null) :
				_root(root),
				_node(node),
				_null(null) {}

			mapIterator(mapIterator const & src) :
				_root(src._root),
				_node(src._node),
				_null(src._null) {}

			virtual ~mapIterator(void) {}

			mapIterator & operator= (mapIterator const & rhs) {
				if (this == &rhs) return *this;

				_root = rhs._root;
				_node = rhs._node;
				_null = rhs._null;
				return *this;
			}
		
		/* operator */
			
			reference	operator* (void) const { return _node->val; }

			pointer		operator->(void) const { return &(operator*()); }

			/** @brief increment node position*/
			mapIterator &	operator++ (void) {
				if (_node == max(_root)) {
					_node = _null;
					return *this;
				}
				else if (_node == _null) {
					_node = ft_nullptr;
					return *this;
				}
				_node = successor(_node);
				return *this;
			}
			
			mapIterator	operator++ (int) {
				mapIterator tmp(_root, _node, _null);
				operator++();
				return tmp;
			}

			/** @brief decrease node position*/
			mapIterator &	operator-- (void) {
				if (_node == _null) {
					_node = max(_root);
					return *this;
				}
				_node = predecessor(_node);
				return *this;
			}
			
			mapIterator	operator-- (int) {
				mapIterator tmp(_root, _node, _null);
				operator--();
				return tmp;
			}

		// here the compare operator is member function
		// because the template 'T' is not the type we want to compare
			bool operator== (const mapIterator & rhs) {
				return _node == rhs._node;
			}

			bool operator!= (const mapIterator & rhs) {
				return _node != rhs._node;
			}

		private:
		/** attributes */
			
			node_pointer _root;
			node_pointer _node;
			node_pointer _null;

		/** private function */
		
			// find the node with the minimum key
			node_pointer	min(node_pointer s) {
				while (s->left != _null)
					s = s->left;
				return s;
			}

			// find the node with the maximum key
			node_pointer	max(node_pointer s) {
				while (s->right != _null)
					s = s->right;
				return s;
			}

			// find the successor of a given node
			node_pointer	successor(node_pointer x) {
				// if the right subtree is not null,
				// the successor is the leftmost node in the
				// right subtree
				if (x->right != _null)
					return min(x->right);

				// else it is the lowest ancestor of x whose
				// left child is also an ancestor of x.
				node_pointer y = x->parent;
				while (y != _null && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			// find the predecessor of a given node
			node_pointer	predecessor(node_pointer s) {
				// if the left subtree is not null,
				// the predecessor is the rightmost node in the 
				// left subtree
				if (s->left != _null)
					return max(s->left);

				node_pointer	tmp = s->parent;
				while (tmp != _null && s == tmp->left) {
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}
	};
}

#endif