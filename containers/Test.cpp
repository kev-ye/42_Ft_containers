/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/09/28 19:56:22 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

int main(void) {
	using namespace std;

	std::map<int, int> first;

	first[2]=30;
	first[1]=10;
	first[3]=50;
	first[4]=70;

	// cout << boolalpha;
	// cout << "empty: " << first.empty() << endl;
	// cout << "size: " << first.size() << endl;
	// cout << "max_size: " << first.max_size() << endl;

	// cout << sizeof(first) << endl;

	// std::map<int, int>::iterator it = first.begin();
	// cout << "it: " << it->first << endl;
	// it++;

	// std::map<int, int>::iterator it2 = it;
	// cout << "it2: " << it2->first << endl;

	// it2++;
	// cout << "it2: " << it2->first << endl;
	// cout << "it: " << it->first << endl;

	std::map<int, int>::iterator it = first.begin();

	cout << it->first << endl;

	it++;
	// it++;
	// it++;
	// it++;

	cout << it->first << endl;

	return 0;
}