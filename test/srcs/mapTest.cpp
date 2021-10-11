/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/10/11 18:48:25 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Custom.hpp"
#include "map.hpp"
#include <map>
#include <iostream>
#include <string>

// #define __NS__ std // default namespace

/**
 * @brief utils
 */

typedef void	(*fp)(void);
struct Test {
	std::string	testName;
	fp const	fptr;
};

void	printTitle(std::string const & title) {
	std::cout << "-- [" << title << "] --" << std::endl;
	std::cout << std::endl;
}

template < class Key, class T >
void	printSize(__NS__::map<Key, T> m) {
	std::cout << "size: " << m.size() << std::endl;
	std::cout << "maxSize: " << m.max_size() << std::endl;
	std::cout << std::endl;
}

template < class Key, class T, class Compare >
void	printSize(__NS__::map<Key, T, Compare> m) {
	std::cout << "size: " << m.size() << std::endl;
	std::cout << "maxSize: " << m.max_size() << std::endl;
	std::cout << std::endl;
}

bool	fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp { bool operator() (const char& lhs, const char& rhs) const { return lhs < rhs; } };

/**
 * @brief constructor test
 */

void	constructTest(void) {
	printTitle("Constructor");

	std::cout << "basic construct: + (a, 10) (b, 20) (c, 30) (d, 40):\n";
	__NS__::map<char, int> m1;
	m1['a'] = 10;
	m1['b'] = 20;
	m1['c'] = 30;
	m1['d'] = 40;
	printSize(m1);
	
	std::cout << "range: m1.begin -> m1.end:\n";
	__NS__::map<char, int> m2(m1.begin(), m1.end());
	printSize(m2);
	
	std::cout << "copy: m3(m2):\n";
	__NS__::map<char, int> m3(m2);
	printSize(m3);

	std::cout << "class as Compare\n";
	__NS__::map<char, int, classcomp> m4; 
	printSize(m4);

	std::cout << "function pointer as Compare\n";
	bool (*fn_pt)(char, char) = fncomp;
	__NS__::map<char, int, bool (*)(char,char)> m5(fn_pt);
	printSize(m4);
}

/**
 * @brief main
 */

int main(int ac, char **av) {
	if (ac == 1) {
		printTitle("Args help");
		
		std::cout << "- \033[1;36mall\033[0m: launch all test\n"
			<< "- \033[1;36mconstructTest\033[0m: launch about constructor test\n"
			<< "- \033[1;36miteratorTest\033[0m: launch about iterator test\n"
			<< "- \033[1;36msizeTest\033[0m: launch about size/max_size/capacity test\n"
			<< "- \033[1;36mresizeTest\033[0m: launch about resize test\n"
			<< "- \033[1;36memptyTest\033[0m: launch about empty test\n"
			<< "- \033[1;36melementAccessTest\033[0m: launch about element access test\n"
			<< "- \033[1;36massignTest\033[0m: launch about assign test\n"
			<< "- \033[1;36mpbTest\033[0m: launch about push_back/pop_back test\n"
			<< "- \033[1;36minsertTest\033[0m: launch about insert test\n"
			<< "- \033[1;36mswaptTest\033[0m: launch about swap test\n"
			<< "- \033[1;36mclearTest\033[0m: launch about clear test\n";
		return 0;
	}

	Test test[] = {
		{"constructTest", &constructTest}
		// {"iteratorTest", &iteratorTest},
		// {"sizeTest", &sizeTest},
		// {"resizeTest", &resizeTest},
		// {"emptyTest", &emptyTest},
		// {"elementAccessTest", &elementAccessTest},
		// {"assignTest", &assignTest},
		// {"pbTest", &pbTest},
		// {"insertTest", &insertTest},
		// {"eraseTest", &eraseTest},
		// {"swapTest", &swapTest},
		// {"clearTest", &clearTest}
		};

	if (std::string(av[1]) == "all") {
		for (int i = 0; i < 1; i++)
			test[i].fptr();
		return 0;
	}

	std::string arg(av[1]);
	for (int i = 0; i < 1; i++) {
		if (test[i].testName == arg) {
			test[i].fptr();
			return 0;
		}
	}

	return 0;
}