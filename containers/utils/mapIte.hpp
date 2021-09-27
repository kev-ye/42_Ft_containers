/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:31:14 by kaye              #+#    #+#             */
/*   Updated: 2021/09/27 17:01:10 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITE_HPP
# define MAPITE_HPP

#include "BST.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {
/**
 * @class template: mapIterator
 */
	
	/**
	 * @class template: mapIterator
	 * @brief bidirectional iterator
	 */
	template < class T >
	class mapIterator : public iterator<bidirectional_iterator_tag, T> {
		public:
		/* member types */

			typedef typename iterator<bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename iterator<bidirectional_iterator_tag, T>::reference			reference;
			typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		
		public:
		/* member functions */

		/* constructor / destructor / operator= */

		private:
		/** attributes */

	};
}

#endif