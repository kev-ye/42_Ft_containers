/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:16 by kaye              #+#    #+#             */
/*   Updated: 2021/09/12 14:05:37 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
// #include <vector>


namespace ft {
	
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
		/* member type */
		
			/** @brief the first template parameter (T) */
			typedef 			T								value_type

			/**
			 * @brief the second template parameter (Alloc)
			 * @note defauls to: allocator<value_type> 
			*/
			typedef 			Alloc							allocator_type

			/**
			 * @brief allocator_type::reference
			 * @note for the default allocator: value_type&
			*/
			typedef typename	allocator_type::reference		reference

			/**
			 * @brief allocator_type::const_reference
			 * @note for the default allocator: const value_type&
			*/
			typedef typename	allocator_type::const_reference	const_reference

			/**
			 * @brief allocator_type::pointer
			 * @note for the default allocator: value_type*
			*/
			typedef typename	allocator_type::pointer			pointer

			/**
			 * @brief allocator_type::cosnt_pointer
			 * @note for the default allocator: const value_type*
			*/
			typedef typename	allocator_type::const_pointer	const_pointer

			/**
			 * @brief a signed integral type, identical to: iterator_traits<iterator>::difference_type
			 * @note usually the same as ptrdiff_t
			*/
			typedef typename	allocator_type::difference_type	difference_type

			/**
			 * @brief an unsigned integral type that can reprensent any non-negative value of difference_type
			 * @note usually the same as size_t
			*/
			typedef typename	allocator_type::size_type		size_type

			// coming soon ...
			// typedef ? iterator
			// typedef ? const_iterator
			// typedef ? reverse_iterator
			// typedef ? const_reverse_iterator

		public:
		/* member functions */
	
			/**
			 * @brief constructor: default
			 * @note constructs an empty container, with no elements.
			 * @param alloc: allocator object.
			*/
			explicit vector(const allocator_type & alloc = allocator_tyoe());

			/**
			 * @brief constructor: fill
			 * @note constructs a container with n elements. Each element is a copy of val.
			 * @param n: initial container size.
			 * @param val: value to fill the container with.
			 * @param alloc: allocator object.
			*/
			explicit vector(size_tyoe n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type());

			/**
			 * @brief constructor: range
			 * @note constructs a container with as many elements as the range [first, last], with each element constructed from its corresponding element in that range, in the same order.
			 * @param first: input iterators to the initial positions in a range.
			 * @param last: input iterator to the final positions in a range.
			 * @param alloc: allocator object.
			*/
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const aloocator_type & alloc = allocator_type());

			/**
			 * @brief constructor: copy
			 * @note constructs a container with a copy of each of the elements in x, in the same order.
			 * @param x: another vector object of the same type, whose contents are either copied or acquired.
			*/
			vector(const vector & x);
			
			virtual ~vector(void);

			vector &	operator=(vector const & rhs);

			/* iterators */
			// begin
			// end
			// rbegin
			// rend

			/* capacity */
			size_type	size(void) const;
			size_type	max_size(void) const;
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity(void) const;
			bool		empty(void) const;
			void		reserve(size_type n);
			void		shrink_to_fit(void);
			
			/* element access */
			
		
	};
}

#endif