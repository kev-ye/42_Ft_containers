/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:31:14 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 08:34:05 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITE_HPP
# define SETITE_HPP

#include "RBT.hpp"
#include "iterator.hpp"
#include "utils.hpp"

#include <iostream>

_BEGIN_NS_FT

/**
 * @class template: setIterator
 */

	/**
	 * @class template: setIterator
	 * @brief bidirectional iterator
	 */
	template < class T, class Node >
	class setIterator : public ft::iterator<bidirectional_iterator_tag, T> {
		public:
		/* member types */

			typedef 			T																		value_type;

			typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename 	ft::iterator<bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename 	ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
			typedef typename 	ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

			typedef Node	node_type;
			typedef Node*	node_pointer;
		
		public:
		/* member functions */

		/* constructor / destructor / operator= */
			
			setIterator(void) :
				_root(ft_nullptr),
				_node(ft_nullptr),
				_null(ft_nullptr) {}

			setIterator(node_pointer root, node_pointer node, node_pointer null) :
				_root(root),
				_node(node),
				_null(null) {}

			setIterator(setIterator const & src) :
				_root(src._root),
				_node(src._node),
				_null(src._null) {}

			~setIterator(void) {}

			setIterator & operator= (setIterator const & rhs) {
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
			setIterator &	operator++ (void) {
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
			
			setIterator	operator++ (int) {
				setIterator tmp(_root, _node, _null);
				operator++();
				return tmp;
			}

			/** @brief decrease node position*/
			setIterator &	operator-- (void) {
				if (_node == _null) {
					_node = max(_root);
					return *this;
				}
				_node = predecessor(_node);
				return *this;
			}
			
			setIterator	operator-- (int) {
				setIterator tmp(_root, _node, _null);
				operator--();
				return tmp;
			}

			operator setIterator<const T, Node> (void) {
				return setIterator<const T, Node>(_root, _node, _null);
			}

			template < class _T, class _Node >
			friend bool operator== (const setIterator<_T, _Node> & lhs, const setIterator<_T, _Node> & rhs) {
				return lhs._node == rhs._node;
			}

			template < class _TL, class _TR, class _Node >
			friend bool operator== (const setIterator<_TL, _Node> & lhs, const setIterator<_TR, _Node> & rhs) {
				return lhs._node == rhs._node;
			}

			template < class _T, class _Node >
			friend bool operator!= (const setIterator<_T, _Node> & lhs, const setIterator<_T, _Node> & rhs) {
				return lhs._node != rhs._node;
			}

			template < class _TL, class _TR, class _Node >
			friend bool operator!= (const setIterator<_TL, _Node> & lhs, const setIterator<_TR, _Node> & rhs) {
				return lhs._node != rhs._node;
			}

		private:
		/** attributes */
			
			node_pointer _root;
			node_pointer _node;
			node_pointer _null;

		/** private function */
			
			node_pointer	min(node_pointer s) {
				while (s->left != _null)
					s = s->left;
				return s;
			}

			node_pointer	max(node_pointer s) {
				while (s->right != _null)
					s = s->right;
				return s;
			}

			node_pointer	successor(node_pointer x) {
				if (x->right != _null)
					return min(x->right);

				node_pointer y = x->parent;
				while (y != _null && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			node_pointer	predecessor(node_pointer s) {
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

_END_NS_FT

#endif