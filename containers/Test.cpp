/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/01 19:01:40 by kaye             ###   ########.fr       */
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

	mymap.insert(std::make_pair<char, int>('a', 50));
	mymap.insert(std::make_pair<char, int>('b', 100));
	mymap.insert(std::make_pair<char, int>('c', 150));
	mymap.insert(std::make_pair<char, int>('d', 200));

	it = mymap.find('f');
	// if (it != mymap.end())
	// 	mymap.erase (it);
	cout << it->first << endl;

	// print content:
	cout << "elements in mymap:" << '\n';
	cout << "a => " << mymap.find('a')->second << '\n';
	cout << "c => " << mymap.find('c')->second << '\n';
	cout << "d => " << mymap.find('d')->second << '\n';

	return 0;
}