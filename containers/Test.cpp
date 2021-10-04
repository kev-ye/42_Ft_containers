/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/04 19:44:03 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

int main(void) {
	using namespace std;

	std::map<int, int> m;

	m.insert(std::make_pair<int, int>(1, 10));
	m.insert(std::make_pair<int, int>(2, 20));
	m.insert(std::make_pair<int, int>(3, 30));
	m.insert(std::make_pair<int, int>(4, 40));

	std::map<int, int>::iterator it = m.begin();

	// it++;
	// it++;
	// it++;
	// it++;
	// it--;
	// it--;
	cout << it->first << endl;

	return 0;
}