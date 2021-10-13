/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSpeed.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:01 by kaye              #+#    #+#             */
/*   Updated: 2021/10/13 14:40:18 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "map.hpp"

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

int main() {
	printTitle("Map run time");

	__NS__::map<int, int> m;
    printSize(m);
	for (int i = 0; i < 1000000; i++)
		m.insert(__NS__::make_pair(i, i));
	printSize(m);
}