	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/09/17 14:10:30 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testClass.hpp"
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

void	printTitle(std::string const & title) {
	std::cout << "-- [" << title << "] --" << std::endl;
	std::cout << std::endl;
}

template < class T >
void	printSize(__NS__::vector<T> vec) {
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "maxSize: " << vec.max_size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
}

void	constructTest(void) {
	printTitle("Constructor")

	std::cout << "empty test: int:\n";
	__NS__::vector<int> vecInt;
	printSize(vec);

	std::cout << "\nempty test: vecCustomClass:\n";
	__NS__::vector<int> vecCustomClass;
	printSize(vec);
	
}

int main(void) {

	printSize(vec);

	return 0;
}