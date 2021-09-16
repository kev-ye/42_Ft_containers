/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:37:13 by kaye              #+#    #+#             */
/*   Updated: 2021/09/16 18:14:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

/**
 * @brief lexicographical less-than comparison
 * @note returns true if the range [first1, last1] compres lexicographically less than the range [first2, last2].
 * 
 * @param first1: input iterators to the initial positions of the first sequence.
 * @param last1: input iterators to the final positions of the first sequence.
 * @param first2: input iterators to the initial positions of the second sequence.
 * @param last2: input iterators to the final positions of the second sequence.
 * @param comp: binary function that accepts two arguments of the types pointed by the iterators, and returns a value convertible to bool.
 * @return true if the first range compares lexicographically less than the second.
 * @return false otherwise.
 */
template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

#endif