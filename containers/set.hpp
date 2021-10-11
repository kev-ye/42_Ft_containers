/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:14 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 13:44:44 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include <memory>
#include <cstddef>
#include <exception>
#include "./utils/treeIte.hpp"

_BEGIN_NS_FT

/**
 * @class template: set
 */

	/**
	 * @brief set
	 * @note sets are associative containers that store elements formed by a combination of a key value and a setped value,
	 * following a specific order.
	 * 
	 * container properties:
	 *  - associative:
	 *   elements in associative containers are referenced by their key and not by their absolute position in the container.
	 *  - ordered:
	 *   the elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
	 *  - set
	 *   each element associates a key to a setped value:
	 *   keys are meant to identify the element whose main content is the setped value.
	 *  - unique keys:
	 *   no two elements in the container can have equivalent keys.
	 *  - allocator-aware:
	 *   the container uses an allocator object to dynamically handle its storage needs.
	 * 
	 * @param key: type of the keys. each element in a set is uniquely identified by its key value.
	 * @param T: type of the setped valu. each element in a set stores somedata as its setped value.
	 * @param Compare: a binary predicate that takes two element keys as arguments and returns a bool.
	 * the expression comp(a,b), where comp is an object of this type and a and b are key values,
	 * shall return true if a is considered to go before b in the strict weak ordering the function defines.
	 * The set object uses this expression to determine both the order the elements follow in the container and whether two element keys are equivalent.
	 * No two elements in a set container can have equivalent keys.
	 * This can be a function pointer or a function object.
	 * This defaults to less<T>, which returns the same as applying the less-than operator (a<b).
	 * @param Alloc: type of the allocator object used to define the storage allocation model.
	 * by default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.
	 */
	template < class T,
		class Compare = ft::less<T>,
		class Alloc = std::allocator<T> >
	class set {
		public:
		/* member types */

			typedef				T													kwy_type;
			typedef				T													value_type;
			typedef				Compare												key_compare;
			typedef				Compare												value_compare;

			typedef				Alloc															allocator_type;
			typedef	typename	allocator_type::reference										reference;
			typedef	typename	allocator_type::const_reference									const_reference;
			typedef	typename	allocator_type::pointer											pointer;
			typedef	typename	allocator_type::const_pointer									const_pointer;
			
			/** @note usually the same as ptrdiff_t */
			typedef	typename	allocator_type::difference_type									difference_type;
			/** @note usually the same as size_t */
			typedef	typename	allocator_type::size_type										size_type;

			typedef				ft::treeIterator<const value_type, ft::RBT_Node<value_type> >	iterator;
			typedef				ft::treeIterator<const value_type, ft::RBT_Node<value_type> >	const_iterator;
			typedef				ft::reverse_iterator<iterator>									reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>							const_reverse_iterator;

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
			explicit set(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _rbt(value_compare(comp)) { (void)alloc; }
		
			/**
			 * @brief constructor: range
			 * @note constructs a container with as many elements as the range [first, last],
			 * with each element constructed from its corresponding element in that range.
			 * 
			 * @param first, last: input iterators to the initial and final positions in a range.
			 * @param alloc: allocator object.
			 */
			template <class InputIterator>
			set(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _rbt(value_compare(comp)) {
					(void)alloc;
					insert(first, last);
			}

			/**
			 * @brief constructor: copy
			 * @note constructs a container with a copy of each of the elements in x.
			 * 
			 * @param x: another vector object of the same type, whose contents are either copied or acquired.
			 */
			set(const set& x) : _rbt(value_compare(key_compare())) {
				insert(x.begin(), x.end());
			}
			
			/**
			 * @brief destructor
			 * @note this destroys all container elements,
			 * and deallocates all the storage capacity allocated by the vector using its allocator.
			 */
   			~set(void) {
				clear();
				_rbt.destroyNull();
			}

			/**
			 * @brief operator: copy
			 * @note copies all the elements from x into the container.
			 * 
			 * @param x: a set object of the same type.
			 * @return *this.
			 */
			set& operator=(const set& x) {
				if (this == &x) return *this;

				this->~set();
				_rbt = ft::RBT<value_type, value_compare>(value_compare(key_compare()));
				insert(x.begin(), x.end());
				return *this;
			}

		/* member functions: iterators */

			/**
			 * @brief return iterator to beginning
			 * @note returns an iterator referring to the first element in the set container.
			 * 
			 * @return an iterator to the first element in the container.
			 */
			iterator begin() { return iterator(_rbt.getRoot(), _rbt.min(), _rbt.getNull()); }
			const_iterator begin() const { return const_iterator(_rbt.getRoot(), _rbt.min(), _rbt.getNull()); }
			
			/**
			 * @brief return iterator to end
			 * @note returns an iterator referring to the past-the-end element in the set container.
			 * 
			 * @return an iterator to the past-the-end element in the container.
			 */
			iterator end() { return iterator(_rbt.getRoot(), _rbt.getNull(), _rbt.getNull()); }
			const_iterator end() const { return const_iterator(_rbt.getRoot(), _rbt.getNull(), _rbt.getNull()); }

			/**
			 * @brief return reverse iterator to reverse beginning
			 * @note returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
			 * 
			 * @return a reverse iterator to the reverse beginning of the sequence container.
			 */
			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			/**
			 * @brief return reverse iterator to reverse end
			 * @note returns a reverse iterator pointing to the theoretical element right
			 * before the first element in the set container (which is considered its reverse end).
			 * 
			 * @return a reverse iterator to the reverse end of the sequence container.
			 */
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/* member functions: capacity */
		
			/**
			 * @brief test whether container is empty
			 * @note returns whether the set container is empty (i.e. whether its size is 0).
			 * 
			 * @return true if the container size is 0, false otherwise.
			 */
			bool		empty() const { return begin() == end(); }

			/**
			 * @brief return container size
			 * @note returns the number of elements in the set container.
			 * 
			 * @return the number of elements in the container.
			 */
			size_type	size() const { return _rbt.size(); }

			/**
			 * @brief return maximum size
			 * @note returns the maximum number of elements that the set container can hold.
			 * 
			 * @return the maximum number of elements a set container can hold as content.
			 */
			size_type	max_size(void) const { return _rbt.max_size(); }

		/* member functions: modifiers */
		
			/**
			 * @brief insert elements
			 * @note extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param val: value to be copied to (or moved as) the inserted element.
			 * @param position: hint for the position where the element can be inserted.
			 * @param first, last: iterators specifying a range of elements.
			 * Copies of the elements in the range [first,last) are inserted in the container.
			 * @return the single element versions (1) return a pair,
			 * with its member pair::first set to an iterator pointing to either the newly inserted element
			 * or to the element with an equivalent key in the set.
			 * The pair::second element in the pair is set to true if a new element was inserted or
			 * false if an equivalent key already existed.
			 * @return the versions with a hint (2) return an iterator pointing to either
			 * the newly inserted element or to the element that already had an equivalent key in the set.
			 */
			ft::pair<iterator, bool> insert(const value_type& val) {
				if (_rbt.insert(val) == false)
					return ft::make_pair(find(val), false);
				return ft::make_pair(find(val), true);
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

			/**
			 * @brief erase elements
			 * @note removes from the set container either a single element or a range of elements ([first,last)).
			 * 
			 * @param position: iterator pointing to a single element to be removed from the set.
			 * @param k: key of the element to be removed from the set.
			 * @param first, last: Iterators specifying a range within the set container to be removed: [first,last).
			 * i.e., the range includes all the elements between first and last,
			 * including the element pointed by first but not the one pointed by last.
			 * @return for the key-based version (2), the function returns the number of elements erased.
			 */
			void  erase(iterator position) {
				erase(*position);
			}
			
			size_type erase(const value_type& val) {
				if (_rbt.deleteNode(val) == false)
					return 0;
				return 1;
			}

			void  erase(iterator first, iterator last) {
				while (first != last) {
					// refix current ptr
					first = find(*first);
					erase(first++);
				}
			}
	
			/**
			 * @brief swap content
			 * @note exchanges the content of the container by the content of x,
			 * which is another set of the same type. Sizes may differ.
			 * 
			 * @param x: Another set container of the same type as this
			 * (i.e., with the same template parameters, Key, T, Compare and Alloc)
			 * whose content is swapped with that of this container.
			 */
			void swap (set& x) { _rbt.swap(x._rbt); }

			/**
			 * @brief clear content
			 * @note removes all elements from the set container (which are destroyed),
			 * leaving the container with a size of 0.
			 */
			void clear() { _rbt.destroyTree(); }

		/* member functions: observers */

			/**
			 * @brief return key comparison object
			 * @note Returns a copy of the comparison object used by the container to compare keys.
			 * 
			 * @return the comparison object.
			 */
			key_compare	key_comp() const { return key_compare(); }
			
			/**
			 * @brief return value comparison object
			 * @note Returns a comparison object that can be used to compare two elements to get whether
			 * the key of the first one goes before the second.
			 * 
			 * @return the comparison object for element values.
			 */
			value_compare  value_comp() const { return value_compare(key_comp()); }

		/* member functions: operations */
		
			/**
			 * @brief get iterator to element
			 * @note searches the container for an element with a key equivalent to k and
			 * returns an iterator to it if found, otherwise it returns an iterator to set::end.
			 * 
			 * @param k: key to be searched for.
			 * @return an iterator to the element,
			 * if an element with specified key is found, or set::end otherwise.
			 */
			iterator find(const value_type& val) {
				return iterator(_rbt.getRoot(), _rbt.searchTree(val), _rbt.getNull());
			}

			const_iterator find(const value_type& val) const {
				return const_iterator(_rbt.getRoot(), _rbt.searchTree(val), _rbt.getNull());
			}

			/**
			 * @brief count elements with a specific key
			 * @note searches the container for elements with a key equivalent to k and returns the number of matches.
			 * 
			 * @param k: key to search for.
			 * @return 1 if the container contains an element whose key is equivalent to k, or zero otherwise.
			 */
			size_type count(const value_type& val) const {
				if (find(val) == end())
					return 0;
				return 1;
			}
			
			/**
			 * @brief return iterator to lower bound
			 * @note returns an iterator pointing to the first element in the container
			 * whose key is not considered to go before k (i.e., either it is equivalent or goes after).
			 * the function uses its internal comparison object (key_comp) to determine this,
			 * returning an iterator to the first element for which key_comp(element_key,k) would return false.
			 * 
			 * @param k: key to search for.
			 * @return an iterator to the the first element in the container
			 * whose key is not considered to go before k, or set::end if all keys are considered to go before k.
			 */
			iterator lower_bound(const value_type& val) {
				return iterator(_rbt.getRoot(), _rbt.lower_bound(val), _rbt.getNull());
			}
			
			const_iterator lower_bound(const value_type& val) const {
				return const_iterator(_rbt.getRoot(), _rbt.lower_bound(val), _rbt.getNull());
			}

			/**
			 * @brief return iterator to upper bound
			 * @note returns an iterator pointing to the first element in the container
			 * whose key is considered to go after k.
			 * the function uses its internal comparison object (key_comp) to determine this,
			 * returning an iterator to the first element for which key_comp(k,element_key) would return true.
			 * 
			 * @param k: key to search for.
			 * @return an iterator to the the first element in the container
			 * whose key is considered to go after k, or set::end if no keys are considered to go after k.
			 */
			iterator upper_bound(const value_type& val) {
				return iterator(_rbt.getRoot(), _rbt.upper_bound(val), _rbt.getNull());
			}
			
			const_iterator upper_bound(const value_type& val) const {
				return const_iterator(_rbt.getRoot(), _rbt.upper_bound(val), _rbt.getNull());
			}

			/**
			 * @brief get range of equal elements
			 * @note returns the bounds of a range that includes
			 * all the elements in the container which have a key equivalent to k.
			 * 
			 * @param k: key to search for.
			 * @return the function returns a pair,
			 * whose member pair::first is the lower bound of the range (the same as lower_bound),
			 * and pair::second is the upper bound (the same as upper_bound).
			 */
			ft::pair<iterator, iterator> equal_range(const value_type& val) {
				return ft::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val));
			}
			
			ft::pair<const_iterator, const_iterator> equal_range(const value_type& val) const {
				return ft::make_pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val));
			}

		/* member functions: allocator */
		
			/**
			 * @brief get allocator
			 * @note returns a copy of the allocator object associated with the set.
			 * 
			 * @return the allocator.
			 */
			allocator_type get_allocator() const { return allocator_type(); }

		private:
		/* attributes */

			ft::RBT<value_type, value_compare>	_rbt;
	};
	
	/* non-member function: vector */

		/**
		 * @brief relational operators for set
		 * @note performs the appropriate comparison operation between the set containers lhs and rhs.
		 * a != b : !(a == b)
		 * a > b  : b < a
		 * a <= b : !(b < a)
		 * a >= b : !(a < b)
		 * 
		 * @param lhs, rhs: set containers (to the left- and right-hand side of the operator, respectively),
		 * having both the same template parameters (Key, T, Compare and Alloc).
		 * @return true if the condition holds, and false otherwise.
		 */
		template <class T, class Compare, class Allocator>
		bool operator==(const ft::set<T, Compare, Allocator>& lhs,
				const ft::set<T, Compare, Allocator>& rhs) {
					if (lhs.size() != rhs.size())
						return false;
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

		template <class T, class Compare, class Allocator>
		bool operator!=(const set<T, Compare, Allocator>& lhs,
				const set<T, Compare, Allocator>& rhs) { return !(lhs == rhs); }

		template <class T, class Compare, class Allocator>
		bool operator< (const set<T, Compare, Allocator>& lhs,
				const set<T, Compare, Allocator>& rhs) {
					return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class T, class Compare, class Allocator>
		bool operator<=(const set<T, Compare, Allocator>& lhs,
				const set<T, Compare, Allocator>& rhs) { return !(rhs < lhs); }

		template <class T, class Compare, class Allocator>
		bool operator> (const set<T, Compare, Allocator>& lhs,
				const set<T, Compare, Allocator>& rhs) { return rhs < lhs; }

		template <class T, class Compare, class Allocator>
		bool operator>=(const set<T, Compare, Allocator>& lhs,
				const set<T, Compare, Allocator>& rhs) { return !(lhs < rhs); }

		template <class T, class Compare, class Allocator>
		void swap(set<T, Compare, Allocator>& x,
			set<T, Compare, Allocator>& y) { x.swap(y); }

_END_NS_FT

#endif
