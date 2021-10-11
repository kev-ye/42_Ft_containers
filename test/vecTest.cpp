/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 08:21:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Custom.hpp"
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

#define __NS__ std // default namespace set

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
	__NS__::vector<Custom> vecCustom;
	printSize(vecCustom);

	std::cout << "\nfill test: int:\n";
	__NS__::vector<int> vecInt2(42);
	printSize(vecInt2);

	std::cout << "\nrange test: int:\n";
	__NS__::vector<int> vecInt3(vecInt2.begin(), vecInt2.end());
	printSize(vecInt3);

	std::cout << "\nrange test2: Custom:\n";
	__NS__::vector<Custom> vecCustom2(10);
	__NS__::vector<Custom>::iterator it = vecCustom2.begin();
	__NS__::vector<Custom>::iterator ite = vecCustom2.end();

	it++;
	ite--;
	__NS__::vector<Custom> vecCustom3(it, ite);
	printSize(vecCustom3);

	std::cout << "\ncopy test: Custom:\n";
	__NS__::vector<Custom> vecCustom4(vecCustom3);
	printSize(vecCustom4);

	std::cout << "\noperator= test: int:\n";
	vecCustom4 = vecCustom;
	printSize(vecCustom4);
}

void	iteratorTest(void) {
	printTitle("Iterator");

	__NS__::vector<int> vecInt;
	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(4);
	vecInt.push_back(5);

	__NS__::vector<int>::iterator it = vecInt.begin();
	__NS__::vector<int>::iterator ite = vecInt.end();
	it++;
	it--;
	it += 1;
	it -= 1;

	__NS__::vector<int>::const_iterator cit = it + 1;
	std::cout << *cit << std::endl;;
	cit = it - 1;
	std::cout << *cit << std::endl;
	
	it[2] = 10;
	std::cout << it[2] << std::endl;

	cit = it;
	if (it == cit)
		std::cout << "it == cit" << std::endl;

	for (; it != ite; it++)
		std::cout << *it << std::endl;
	
	printSize(vecInt);
}

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "all run coming soon ..\n";
	}

	if (std::string(av[1]) == "constructTest")
		constructTest();

	if (std::string(av[1]) == "iteratorTest")
		iteratorTest();

	return 0;
}