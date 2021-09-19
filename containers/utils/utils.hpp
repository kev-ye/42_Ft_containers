/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:37:13 by kaye              #+#    #+#             */
/*   Updated: 2021/09/19 20:31:24 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
	/* 
	 * class(template): enable_if
	 */
	
	/**
	 * @brief enable type if condition is met
	 * @note the type T is enabled as member type enable_if::type if Cond is true.
	 * 
	 * @param cond: a compile-time constant of type bool.
	 * @param T: a type
	 */
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	/*
	 * class(template): integral_constant
	 */
	
	/**
	 * @brief Integral constant
	 * @note this template is designed to provide compile-time constants as types
	 * 
	 * @param T: type of the integral constant.
	 * @param v: value of the integral constant.
	 */
	template <class T, T v>
	struct integral_constant {
		static constexpr T value = v;

		/* member types */

		/** @brief the type of the constant */
		typedef T value_type;

		/** @brief the integral_constant type itself */
		typedef integral_constant<T, v> type;

		/* instantiations */

		/**
		 * @brief returns value
		 * @note returns the value of the integral_constant.
		 * 
		 * @return the value of the integral_constant.
		 */
		constexpr operator T(void) { return v; }
	};

	/*
	 * class(template): integral_constant: instantiations
	 */
	
	/**
	 * @brief true type
	 * @note Instantiation of integral_constant to represent the bool value true.
	 */
	typedef integral_constant<bool, true>	true_type;

	/**
	 * @brief false type
	 * @note Instantitation of integral_constant to represent the bool value false.
	 */
	typedef integral_constant<bool, false>	false_type;

	/*
	 * class(template): is_integral
	 */

	// /** 
	//  * @brief is integral
	//  * @note trait class that identifies whether T is an integral type.
	//  */
	// template < class T >
	// struct is_integral {
	// 	bool	value_type
		
	// }

	/*
	 * function: equal
	 */

	/**
	 * @brief test whether the elements in two ranges are equal
	 * @note compares the elements in the range [first1, last1] with those i nthe range beginning at first2, and returns true if all of the elements in both ranges match.
	 * 
	 * @param first1, last1: Input iterators to the initial and final positions of the first sequence.
	 * @param first2: input iterator to the initial position of the second sequence.
	 * @param pred: Binary function that accepts two elements as argument (one of each of the two sequences, in the same order), and returns a value convertible to bool.
	 * @return true if all the elements in the range [first1, last1] compare equal to those of the range starting at first2.
	 * @return false otherwise.
	 */
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!pred(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	/*
	 * function: lexicographical_compare
	 */

	/**
	 * @brief lexicographical less-than comparison
	 * @note returns true if the range [first1, last1] compres lexicographically less than the range [first2, last2].
	 * 
	 * @param first1, last1: input iterators to the initial and final positions of the first sequence.
	 * @param first2, last2: input iterators to the initial and final positions of the second sequence.
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
};
#endif