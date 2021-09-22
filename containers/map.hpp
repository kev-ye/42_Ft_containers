/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:14 by kaye              #+#    #+#             */
/*   Updated: 2021/09/22 17:22:44 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <exception>
#include "./utils/utils.hpp"

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

	};
}

#endif
