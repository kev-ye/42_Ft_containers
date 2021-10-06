/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/05 19:52:00 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

int main(void) {
	using namespace std;

	// std::map<int, int> m;

	// m.insert(std::make_pair<int, int>(1, 10));
	// m.insert(std::make_pair<int, int>(2, 20));
	// m.insert(std::make_pair<int, int>(3, 30));
	// m.insert(std::make_pair<int, int>(4, 40));

	// std::map<int, int>::iterator it = m.begin();

	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// // it--;
	// // it--;
	// cout << it->first << endl;

	std::map<char,int> m;
	// std::map<char,int>::iterator it;

	// insert some values:
	// m.insert(std::make_pair<char, int>('a', 10));
	// m.insert(std::make_pair<char, int>('b', 20));
	// m.insert(std::make_pair<char, int>('c', 30));
	// m.insert(std::make_pair<char, int>('d', 40));
	// m.insert(std::make_pair<char, int>('e', 50));
	// m.insert(std::make_pair<char, int>('f', 60));

	// m.debug();

	// it = m.find('a');
	// m.erase (it);                   // erasing by iterator

	// m.erase('c');                  // erasing by key

	// it = m.find ('e');
	// m.erase (it, m.end());    // erasing by range

	// // show content:
	// // for (it = m.begin(); it != m.end() ; ++it) {
	// // 	cout << it->first << "\n";
	// // 	m.erase(it);
	// // }

	// it = m.begin();
	// std::map<char,int>::iterator ite = m.end();
	// // for (it=m.begin(); it != m.end() ; it++) 
	// while(it != ite) {
	// 	cout << it->first << " => " << it->second << '\n';
	// 	it++;
	// }

	cout << m.max_size() << endl;

	return 0;
}