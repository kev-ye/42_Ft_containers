/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackRunTime.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:03 by kaye              #+#    #+#             */
/*   Updated: 2021/10/13 15:03:54 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "stack.hpp"

void	printTitle(std::string const & title) {
	std::cout << "-- [" << title << "] --" << std::endl;
	std::cout << std::endl;
}

template < class T, class Container >
void	printSize(__NS__::stack<T, Container> stack) {
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << std::endl;
}

int main() {
    printTitle("Stack run time");

	__NS__::stack<int> stk;
    printSize(stk);
	for (int i = 0; i < 1000000; i++)
		stk.push(i);
	printSize(stk);
}