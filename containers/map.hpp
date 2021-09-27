/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:14 by kaye              #+#    #+#             */
/*   Updated: 2021/09/27 19:34:19 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <exception>
#include "./utils/mapIte.hpp"

namespace ft {
/**
 * @class template: map
 */

	/**
	 * @brief map
	 * @note maps are associative containers that store elements formed by a combination of a key value and a mapped value,
	 * following a specific order.
	 * 
	 * container properties:
	 *  - associative:
	 *   elements in associative containers are referenced by their key and not by their absolute position in the container.
	 *  - ordered:
	 *   the elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
	 *  - map
	 *   each element associates a key to a mapped value:
	 *   keys are meant to identify the element whose main content is the mapped value.
	 *  - unique keys:
	 *   no two elements in the container can have equivalent keys.
	 *  - allocator-aware:
	 *   the container uses an allocator object to dynamically handle its storage needs.
	 * 
	 * @param key: type of the keys. each element in a map is uniquely identified by its key value.
	 * @param T: type of the mapped valu. each element in a map stores somedata as its mapped value.
	 * @param Compare: a binary predicate that takes two element keys as arguments and returns a bool.
	 * the expression comp(a,b), where comp is an object of this type and a and b are key values,
	 * shall return true if a is considered to go before b in the strict weak ordering the function defines.
	 * The map object uses this expression to determine both the order the elements follow in the container and whether two element keys are equivalent.
	 * No two elements in a map container can have equivalent keys.
	 * This can be a function pointer or a function object.
	 * This defaults to less<T>, which returns the same as applying the less-than operator (a<b).
	 * @param Alloc: type of the allocator object used to define the storage allocation model.
	 * by default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.
	 */
	template < class Key,
		class T,
		class Compare = ft::less<Key>,
		class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {
		public:
		/* member types */

			typedef				Key										key_type;
			typedef				T										mapped_type;
			typedef				ft::pair<const key_type, mapped_type>	value_type;
			typedef				Compare									key_compare;

			typedef				Alloc									allocator_type;
			typedef	typename	allocator_type::reference				reference;
			typedef	typename	allocator_type::const_reference			const_reference;
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;
			
			/** @note usually the same as ptrdiff_t */
			typedef	typename	allocator_type::difference_type			difference_type;
			/** @note usually the same as size_t */
			typedef	typename	allocator_type::size_type				size_type;

			// typedef	implementation-defined							iterator;
			// typedef	implementation-defined							const_iterator;
			// typedef	std::reverse_iterator<iterator>					reverse_iterator;
			// typedef	std::reverse_iterator<const_iterator>			const_reverse_iterator;

			class value_compare : public binary_function<value_type, value_type, bool> {
				friend class map;
		
				protected:
					key_compare comp;

					value_compare(key_compare c) : comp(c) {}

				public:
					typedef bool 		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

		public:
		/* member functions: constructor / destructor / operator= */
		
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_comp(comp),
					_bst() {}
		
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

			map(const map& x) :
				_alloc(x._alloc),
				_comp(x._comp),
				_bst(x._bst) {}
			
   			~map(void) {}

			map& operator=(const map& x) {
				if (this == &x) return *this;

				_alloc = x._alloc;
				_comp = x._comp;
				_bst = x._bst;
				return *this;
			}

		/* member functions: iterators */
		
			// iterator begin();
			// const_iterator begin() const;
			
			// iterator end() ;
			// const_iterator end() const ;

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

		/* member functions: capacity */
		
			bool		empty() const { return size() == 0 ? true : false; }

			size_type	size() const { return _bst.getSize(); }

			size_type	max_size(void) const { return _bst.getMax_size(); }

		/* member functions: element access */
			
			mapped_type& operator[](const key_type& k);

		/* member functions: modifiers */
		
			// ft::pair<iterator, bool> insert(const value_type& val);

			// iterator insert(iterator position, const value_type& val);

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last);

			// iterator  erase(const_iterator position);
			
			size_type erase(const key_type& k);
			
			// iterator  erase(iterator first, iterator last);
	
			void swap (map& x);

			void clear();


		/* member functions: observers */

			key_compare	key_comp() const;
			
			value_compare  value_comp() const;

		/* member functions: operations */
		
			// iterator find(const key_type& k);

			// const_iterator find(const key_type& k) const;

			size_type count(const key_type& k) const;
			
			// iterator lower_bound(const key_type& k);
			
			// const_iterator lower_bound(const key_type& k) const;

			// iterator upper_bound(const key_type& k);
			
			// const_iterator upper_bound(const key_type& k) const;

			// // ft::pair<iterator, iterator> equal_range(const key_type& k);
			
			// // ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

		/* member functions: allocator */
		
			allocator_type get_allocator() const { return _alloc; }

		private:
		/* attributes */

			allocator_type		_alloc;
			key_compare			_comp;
			ft::BST<value_type>	_bst;
	};
	
	/* non-member function: vector */

		template <class Key, class T, class Compare, class Allocator>
		bool operator==(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		bool operator< (const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		bool operator!=(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		bool operator> (const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		bool operator>=(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		bool operator<=(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs);

		template <class Key, class T, class Compare, class Allocator>
		void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y);

}

#endif
