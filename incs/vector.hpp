/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:16 by kaye              #+#    #+#             */
/*   Updated: 2021/09/10 15:15:21 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
// #include <vector>

namespace ft {
	
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		/* member type */
		public:
			typedef 			T								value_type
			typedef 			Alloc							allocator_type
			typedef typename	allocator_type::reference		reference
			typedef typename	allocator_type::const_reference	const_reference
			typedef typename	allocator_type::pointer			pointer
			typedef typename	allocator_type::const_pointer	const_pointer
			typedef typename	allocator_tyoe::difference_type	difference_type
			typedef typename	allocator_tyoe::size_type		size_type

			// coming soon ...
			// typedef ? iterator
			// typedef ? const_iterator // c++11?
			// typedef ? reverse_iterator
			// typedef ? const_reverse_iterator // c++11?
	};
}

#endif