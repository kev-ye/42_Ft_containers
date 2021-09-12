/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:47:24 by kaye              #+#    #+#             */
/*   Updated: 2021/09/12 15:59:17 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include <memory>
#include <limits>

int main(void) {
{
	using namespace std;

	vector<long> vec;

	cout << "size: " << vec.size() << endl;
	cout << "max size: " << vec.max_size() << endl;
}
// {
// 	using namespace ft;
	
// 	ft::vector<long> vec;

// 	std::cout << "size: " << vec.size() << std::endl;
// 	std::cout << "max size: " << vec.max_size() << std::endl;
// }
	return 0;
}