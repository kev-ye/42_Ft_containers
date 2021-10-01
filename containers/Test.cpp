/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/01 18:08:40 by kaye             ###   ########.fr       */
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

	std::map<int,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<int,int>(1,100) );
	mymap.insert ( std::pair<int,int>(2,200) );

	std::pair<std::map<int,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<int,int>(3, 500) );
	// if (ret.second==false) {
	// 	cout << "element 'z' already existed";
	// 	cout << " with a value of " << ret.first->second << '\n';
	// }
	// else {
	// 	cout << " with a value of " << ret.first->second << '\n';
	// }

	// second insert function version (with hint position):
	std::map<int,int>::iterator it = mymap.begin();

	it++;

	mymap.insert (it, std::pair<int,int>(4,300));  // max efficiency inserting
	mymap.insert (it, std::pair<int,int>(5,400));  // no max efficiency inserting
	int i = 0;
	while (i < 30)
		mymap.insert (it, std::pair<int,int>(6 + i++, 400));  // no max efficiency inserting

	it = mymap.begin();

	for (;it != mymap.end(); it++)
		cout << it->first << endl;


	return 0;
}