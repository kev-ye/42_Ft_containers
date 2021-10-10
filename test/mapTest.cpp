/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 00:09:08 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Custom.hpp"
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
	printTitle("Constructor");

	std::cout << "empty test: int:\n";
	__NS__::vector<int> vecInt;
	printSize(vecInt);

	std::cout << "\nempty test: Custom Class:\n";
	__NS__::vector<Custom> vecCustomClass;
	printSize(vecCustomClass);

	std::cout << "\nfill test: int:\n";
	__NS__::vector<int> vecInt2(42);
	printSize(vecInt2);

	std::cout << "\nrange test: int:\n";
	// __NS__::vector<int> vecInt3(vecInt2.begin(), vecInt2.end());
	// printSize(vecInt3);

	std::cout << "\nrange test2: int:\n";
	__NS__::vector<int>::iterator it = vecInt2.begin();
	__NS__::vector<int>::iterator ite = vecInt2.end();

	// it++;
	// ite--;
	__NS__::vector<int> vecInt4(it, ite);
	printSize(vecInt4);

	std::cout << "\ncopy test: int:\n";
	__NS__::vector<int> vecInt5(vecInt4);
	printSize(vecInt5);
}

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "all run coming soon ..\n";
	}

	if (std::string(av[1]) == "constructTest")
		constructTest();

	return 0;
}