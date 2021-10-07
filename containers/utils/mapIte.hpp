/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:31:14 by kaye              #+#    #+#             */
/*   Updated: 2021/10/07 18:53:46 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITE_HPP
# define MAPITE_HPP

#include "RBT.hpp"
#include "iterator.hpp"
#include "utils.hpp"

#include <iostream>

_BEGIN_NS_FT

/**
 * @class template: mapIterator
 */

	/**
	 * @class template: mapIterator
	 * @brief bidirectional iterator
	 */
	template < class T, class Node >
	class mapIterator : public ft::iterator<bidirectional_iterator_tag, T> {
		public:
		/* member types */

			typedef				T																			value_type;

			typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::reference				reference;
			typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category		iterator_category;

			typedef Node	node_type;
			typedef Node*	node_pointer;
		
		public:
		/* member functions */

		/* constructor / destructor / operator= */
			
			mapIterator(void) :
				_root(ft_nullptr),
				_node(ft_nullptr),
				_null(ft_nullptr) {}

			explicit mapIterator(node_pointer root, node_pointer node, node_pointer null) :
				_root(root),
				_node(node),
				_null(null) {}

			mapIterator(mapIterator const & src) :
				_root(src._root),
				_node(src._node),
				_null(src._null) {}

			~mapIterator(void) {}

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

// /**
//  * @class template: const_mapIterator
//  */
	
// 	/**
// 	 * @class template: const_mapIterator
// 	 * @brief bidirectional iterator
// 	 */
// 	template < class T >
// 	class const_mapIterator : public ft::iterator<bidirectional_iterator_tag, T> {
// 		public:
// 		/* member types */

// 			typedef typename T::value_type																value_type;

// 			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::difference_type		difference_type;
// 			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::pointer				pointer;
// 			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
// 			typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

// 			typedef T	node_type;
// 			typedef T*	node_pointer;
		
// 		public:
// 		/* member functions */

// 		/* constructor / destructor / operator= */
			
// 			const_mapIterator(void) :
// 				_root(ft_nullptr),
// 				_node(ft_nullptr),
// 				_null(ft_nullptr) {}

// 			explicit const_mapIterator(node_pointer root, node_pointer node, node_pointer null) :
// 				_root(root),
// 				_node(node),
// 				_null(null) {}

// 			const_mapIterator(const_mapIterator const & src) :
// 				_root(src._root),
// 				_node(src._node),
// 				_null(src._null) {}

// 			~const_mapIterator(void) {}

// 			const_mapIterator & operator= (const_mapIterator const & rhs) {
// 				if (this == &rhs) return *this;

// 				_root = rhs._root;
// 				_node = rhs._node;
// 				_null = rhs._null;
// 				return *this;
// 			}
		
// 		/* operator */
			
// 			reference	operator* (void) const { return _node->val; }

// 			pointer		operator->(void) const { return &(operator*()); }

// 			/** @brief increment node position*/
// 			const_mapIterator &	operator++ (void) {
// 				if (_node == max(_root)) {
// 					_node = _null;
// 					return *this;
// 				}
// 				else if (_node == _null) {
// 					_node = ft_nullptr;
// 					return *this;
// 				}
// 				_node = successor(_node);
// 				return *this;
// 			}
			
// 			const_mapIterator	operator++ (int) {
// 				const_mapIterator tmp(_root, _node, _null);
// 				operator++();
// 				return tmp;
// 			}

// 			/** @brief decrease node position*/
// 			const_mapIterator &	operator-- (void) {
// 				if (_node == _null) {
// 					_node = max(_root);
// 					return *this;
// 				}
// 				_node = predecessor(_node);
// 				return *this;
// 			}
			
// 			const_mapIterator	operator-- (int) {
// 				const_mapIterator tmp(_root, _node, _null);
// 				operator--();
// 				return tmp;
// 			}

// 			bool operator== (const const_mapIterator & rhs) {
// 				return _node == rhs._node;
// 			}

// 			bool operator!= (const const_mapIterator & rhs) {
// 				return _node != rhs._node;
// 			}

// 		private:
// 		/** attributes */
			
// 			node_pointer _root;
// 			node_pointer _node;
// 			node_pointer _null;

// 		/** private function */
			
// 			node_pointer	min(node_pointer s) {
// 				while (s->left != _null)
// 					s = s->left;
// 				return s;
// 			}

// 			node_pointer	max(node_pointer s) {
// 				while (s->right != _null)
// 					s = s->right;
// 				return s;
// 			}

// 			node_pointer	successor(node_pointer x) {
// 				if (x->right != _null)
// 					return min(x->right);

// 				node_pointer y = x->parent;
// 				while (y != _null && x == y->right) {
// 					x = y;
// 					y = y->parent;
// 				}
// 				return y;
// 			}

// 			node_pointer	predecessor(node_pointer s) {
// 				if (s->left != _null)
// 					return max(s->left);

// 				node_pointer	tmp = s->parent;
// 				while (tmp != _null && s == tmp->left) {
// 					s = tmp;
// 					tmp = tmp->parent;
// 				}
// 				return tmp;
// 			}
// 	};

_END_NS_FT

#endif