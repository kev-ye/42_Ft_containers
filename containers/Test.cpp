/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/03 19:44:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

int main(void) {
	using namespace std;

	// std::map<int, int> first;

	// first[2]=20;
	// first[1]=10;
	// first[3]=30;
	// first[4]=40;

	// cout << boolalpha;
	// cout << "empty: " << first.empty() << endl;
	// cout << "size: " << first.size() << endl;
	// cout << "max_size: " << first.max_size() << endl;

	// cout << sizeof(first) << endl;

	// std::map<int, int>::iterator it = first.begin();
	// std::map<int, int>::const_iterator cit = first.begin();

	// it--;

	// cout << "it: " << it->first << endl;
	// it++;

	// if (it == cit)
	// 	cout << "ok\n";

	// std::map<int, int>::iterator it2 = it;
	// cout << "it2: " << it2->first << endl;

	// it2++;
	// cout << "it2: " << it2->first << endl;
	// cout << "it: " << it->first << endl;

	// first.erase(2);

	// std::map<int, int>::iterator it = first.begin();
	// cout << first[1] << endl;

	// cout << it->first << endl;

	// it++;
	// it++;
	// it++;
	// it++;
	// it--;

	// cout << it->first << endl;

	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['c']=30;
	mymap['a']=10;
	mymap['b']=20;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	// mymap.insert(std::make_pair<char, int>('a', 10));
	// mymap.insert(std::make_pair<char, int>('b', 20));
	// mymap.insert(std::make_pair<char, int>('c', 30));
	// mymap.insert(std::make_pair<char, int>('d', 40));
	// mymap.insert(std::make_pair<char, int>('e', 50));
	// mymap.insert(std::make_pair<char, int>('f', 60));

	it = mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('f');                  // erasing by key

	it = mymap.find ('c');
	// std::map<char,int>::iterator ite = mymap.find('f');
	std::map<char,int>::iterator ite = mymap.end();
	mymap.erase ( it, ite );    // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it) {
		cout << it->first << " => " << it->second << '\n';
	}

	return 0;
}