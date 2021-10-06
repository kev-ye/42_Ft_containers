/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:14 by kaye              #+#    #+#             */
/*   Updated: 2021/10/06 20:14:05 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <exception>
#include "./utils/mapIte.hpp"

_BEGIN_NS_FT

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

			typedef				Key													key_type;
			typedef				T													mapped_type;
			typedef				ft::pair<const key_type, mapped_type>				value_type;
			typedef				Compare												key_compare;

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

			typedef				Alloc												allocator_type;
			typedef	typename	allocator_type::reference							reference;
			typedef	typename	allocator_type::const_reference						const_reference;
			typedef	typename	allocator_type::pointer								pointer;
			typedef	typename	allocator_type::const_pointer						const_pointer;
			
			/** @note usually the same as ptrdiff_t */
			typedef	typename	allocator_type::difference_type						difference_type;
			/** @note usually the same as size_t */
			typedef	typename	allocator_type::size_type							size_type;

			typedef	typename	ft::RBT<value_type, value_compare>::iterator		iterator;
			typedef	typename	ft::RBT<value_type, value_compare>::const_iterator	const_iterator;
			typedef				ft::reverse_iterator<iterator>						reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		public:
		/* member functions: constructor / destructor / operator= */

			/**
			 * @brief constructor: default
			 * @note constructs an empty container, with no elements.
			 * 
			 * @param comp: binary predicate that, taking two element keeys as argument,
			 * returns true if the first argument goes before the second argument in the strict weak ordering it defines,
			 * and false otherwise.
			 * @param alloc: allocator object.
			 */
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _rbt(value_compare(comp)) {}
		
			/**
			 * @brief constructor: range
			 * @note constructs a container with as many elements as the range [first, last],
			 * with each element constructed from its corresponding element in that range.
			 * 
			 * @param first, last: input iterators to the initial and final positions in a range.
			 * @param alloc: allocator object.
			 */
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

			/**
			 * @brief constructor: copy
			 * @note constructs a container with a copy of each of the elements in x.
			 * 
			 * @param x: another vector object of the same type, whose contents are either copied or acquired.
			 */
			map(const map& x) { insert(x.begin(), x.end()); }
			
			/**
			 * @brief destructor
			 * @note this destroys all container elements,
			 * and deallocates all the storage capacity allocated by the vector using its allocator.
			 */
   			~map(void) { clear(); }

			/**
			 * @brief operator: copy
			 * @note copies all the elements from x into the container.
			 * 
			 * @param x: a map object of the same type.
			 * @return *this.
			 */
			map& operator=(const map& x) {
				if (this == &x) return *this;

				clear();
				insert(x.begin(), x.end());
				return *this;
			}

		/* member functions: iterators */
		
			iterator begin() { return iterator(_rbt.getRoot(), _rbt.min(), _rbt.getNull()); }
			const_iterator begin() const { return const_iterator(_rbt.getRoot(), _rbt.min(), _rbt.getNull()); }
			
			iterator end() { return iterator(_rbt.getRoot(), _rbt.getNull(), _rbt.getNull()); }
			const_iterator end() const { return const_iterator(_rbt.getRoot(), _rbt.getNull(), _rbt.getNull()); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/* member functions: capacity */
		
			bool		empty() const { return begin() == end(); }

			size_type	size() const { return _rbt.size(); }

			size_type	max_size(void) const { return _rbt.max_size(); }

		/* member functions: element access */
			
			mapped_type& operator[](const key_type& k) {
				insert(ft::make_pair(k, mapped_type()));
				
				iterator it = find(k);
				return ((*it).second);
			}

		/* member functions: modifiers */
		
			ft::pair<iterator, bool> insert(const value_type& val) {
				return _rbt.insert(val);
			}

			iterator insert(iterator position, const value_type& val) {
				(void)position;
				return insert(val).first;
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (; first != last; first++)
					insert(*first);
			}

			void  erase(iterator position) {
				erase(position->first);
			}
			
			size_type erase(const key_type& k) {
				if (find(k) == end())
					return 0;
				_rbt.deleteNode(ft::make_pair(k, mapped_type()));
				return 1;
			}

			void  erase(iterator first, iterator last) {
				while (first != last) {
					erase(first++);
					// first++;
					// seg if we advance the ptr after "erase", because we lost the ptr.
				}
			}
	
			void swap (map& x) {
				_rbt.swap(x._rbt);
			}

			void clear() { _rbt.destroyTree(); }


		/* member functions: observers */

			key_compare	key_comp() const { return key_compare(); }
			
			value_compare  value_comp() const { return value_compare(); }

		/* member functions: operations */
		
			iterator find(const key_type& k) {
				return iterator(_rbt.getRoot(), _rbt.searchTree(ft::make_pair(k, mapped_type())), _rbt.getNull());
			}

			// const_iterator find(const key_type& k) const;

			size_type count(const key_type& k) const {
				if (find(k) == end())
					return 0;
				return 1;
			}
			
			iterator lower_bound(const key_type& k) {
				iterator it = begin();

				for (; it != end(); it++) {
					if (key_compare()(it->first, k) == false)
						break ;
				}
				return it;
			}
			
			// const_iterator lower_bound(const key_type& k) const;

			iterator upper_bound(const key_type& k) {
				iterator it = begin();

				for (; it != end(); it++) {
					if (key_compare()(k, it->first) == true)
						break ;
				}
				return it;
			}
			
			// const_iterator upper_bound(const key_type& k) const;

			ft::pair<iterator, iterator> equal_range(const key_type& k) {
				return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}
			
			// ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

		/* member functions: allocator */
		
			allocator_type get_allocator() const { return allocator_type(); }

		private:
		/* attributes */

			ft::RBT<value_type, value_compare>	_rbt;
	};
	
	/* non-member function: vector */

		template < class T >
		bool equalUtils(T a, T b) {
			return a == b;
		}

		template <class Key, class T, class Compare, class Allocator>
		bool operator==(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs) {
					if (lhs.size() != rhs.size())
						return false;
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), equalUtils);
		}

		template <class Key, class T, class Compare, class Allocator>
		bool operator!=(const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs) {
					return !(lhs == rhs);
		}

		template <class Key, class T, class Compare, class Allocator>
		bool operator< (const map<Key, T, Compare, Allocator>& lhs,
				const map<Key, T, Compare, Allocator>& rhs) {
					
		}

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
		void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y) {
			x.swap(y);
		}

_END_NS_FT

#endif
