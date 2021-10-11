/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 10:35:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Custom.hpp"
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

// #define __NS__ std // default namespace set

void	printTitle(std::string const & title) {
	std::cout << "-- [" << title << "] --" << std::endl;
	std::cout << std::endl;
}

template < class T >
void	printSize(__NS__::vector<T> vec) {
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "maxSize: " << vec.max_size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << std::endl;
}

void	constructTest(void) {
	printTitle("Constructor");

	std::cout << "empty test: int:\n";
	__NS__::vector<int> vecInt;
	printSize(vecInt);

	std::cout << "empty test: Custom Class:\n";
	__NS__::vector<Custom> vecCustom;
	printSize(vecCustom);

	std::cout << "fill test: int:\n";
	__NS__::vector<int> vecInt2(42);
	printSize(vecInt2);

	std::cout << "range test: int:\n";
	__NS__::vector<int> vecInt3(vecInt2.begin(), vecInt2.end());
	printSize(vecInt3);

	std::cout << "range test2: Custom:\n";
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

	it += 1;
	std::cout << "it + 1: " << *it << std::endl;;
	__NS__::vector<int>::const_iterator cit = it - 1;
	std::cout << "it - 1: " << *cit << std::endl;
	
	it[2] = 10;
	std::cout << "it[2] = 10: " << it[2] << std::endl;

	cit = it;
	if (it == cit)
		std::cout << "if it == cit: " << "Yes" << std::endl;
	else
		std::cout << "if it == cit: " << "No" << std::endl;

	for (; it != ite; it++)
		std::cout << "*it: " << *it << std::endl;
	printSize(vecInt);

	__NS__::vector<int>::reverse_iterator rit = vecInt.rbegin();
	__NS__::vector<int>::reverse_iterator rite = vecInt.rend();

	for (; rit != rite; rit++)
		std::cout << "*rit: " << *rit << std::endl;
	printSize(vecInt);
}

void	sizeTest(void) {
	printTitle("Size/Max_size/Capacity");
	
	__NS__::vector<int> vecInt;
	std::cout << "int: ";
	vecInt.push_back(42);
	printSize(vecInt);

	__NS__::vector<char> vecChar;
	std::cout << "char: ";
	printSize(vecChar);

	__NS__::vector<long> vecLong;
	std::cout << "long: ";
	vecLong.push_back(42);
	printSize(vecLong);

	__NS__::vector<long long> vecLongLong;
	std::cout << "longlong: ";
	printSize(vecLongLong);

	__NS__::vector<bool> vecBool;
	std::cout << "bool: ";
	vecBool.push_back(true);
	printSize(vecBool);

	__NS__::vector<Custom> vecCuston;
	std::cout << "custom: ";
	printSize(vecCuston);
}

void resizeTest(void) {
	printTitle("resize/reserve");

	std::cout << "int: ";
	__NS__::vector<int> vecInt;
	printSize(vecInt);

	vecInt.push_back(1);
	printSize(vecInt);

	vecInt.resize(42);
	printSize(vecInt);

	vecInt.resize(0);
	printSize(vecInt);

	vecInt.reserve(42);
	printSize(vecInt);

	for (int i = 42; i < 42; i++)
		vecInt.push_back(i);
	printSize(vecInt);

	vecInt.reserve(0);
	printSize(vecInt);

	std::cout << "Custom: ";
	__NS__::vector<Custom> vecCustom;
	printSize(vecCustom);

	vecCustom.push_back(Custom(1, "Custom"));
	printSize(vecCustom);

	vecCustom.resize(42);
	printSize(vecCustom);

	vecCustom.resize(0);
	printSize(vecCustom);

	vecCustom.reserve(42);
	printSize(vecCustom);

	for (int i = 42; i < 42; i++)
		vecCustom.push_back(Custom(i, "Custom"));
	printSize(vecCustom);

	vecCustom.reserve(0);
	printSize(vecCustom);
}

void emptyTest(void) {
	printTitle("empty");

	std::cout << "int: ";
	__NS__::vector<int> vecInt;

	std::cout << (vecInt.empty() == true ? "vecInt is empty" : "vecInt is not empty") << std::endl;

	vecInt.push_back(1);

	std::cout << (vecInt.empty() == true ? "vecInt is empty\n" : "vecInt is not empty\n") << std::endl;

	std::cout << "Custom: ";
	__NS__::vector<Custom> vecCustom;

	std::cout << (vecCustom.empty() == true ? "vecCustom is empty" : "vecCustom is not empty") << std::endl;

	vecCustom.push_back(Custom(1, "custom"));

	std::cout << (vecCustom.empty() == true ? "vecCustom is empty" : "vecCustom is not empty") << std::endl;
}

typedef void	(*fp)(void);
struct Test {
	std::string	testName;
	fp const	fptr;
};

int main(int ac, char **av) {
	if (ac == 1) {
		printTitle("Args help");
		
		std::cout << "- all\n"
			<< "- constructTest\n"
			<< "- iteratorTest\n"
			<< "- sizeTest\n"
			<< "- resizeTest\n"
			<< "- emptyTest\n";
	}

	Test test[] = {
		{"constructTest", &constructTest},
		{"iteratorTest", &iteratorTest},
		{"sizeTest", &sizeTest},
		{"resizeTest", &resizeTest},
		{"emptyTest", &emptyTest}};

	if (std::string(av[1]) == "all")
		std::cout << "coming soon ...\n";

	std::string arg(av[1]);
	for (int i = 0; i < 5; i++) {
		if (test[i].testName == arg) {
			test[i].fptr();
			return 0;
		}
	}

	return 0;
}