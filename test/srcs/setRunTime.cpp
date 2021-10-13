/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setRunTime.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:34:58 by kaye              #+#    #+#             */
/*   Updated: 2021/10/13 15:08:30 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include "set.hpp"

void	printTitle(std::string const & title) {
	std::cout << "-- [" << title << "] --" << std::endl;
	std::cout << std::endl;
}

template < class T >
void	printSize(__NS__::set<T> s) {
	std::cout << "size: " << s.size() << std::endl;
	std::cout << "maxSize: " << s.max_size() << std::endl;
	std::cout << std::endl;
}

int main() {
	printTitle("Set run time");

	__NS__::set<int> s;
    printSize(s);
	for (int i = 0; i < 1000000; i++)
		s.insert(i);
	printSize(s);
}