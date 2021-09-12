/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:47:24 by kaye              #+#    #+#             */
/*   Updated: 2021/09/12 18:59:09 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

// #include <memory>

void vecSizeTest(void) {
	std::cout << "-- Size --" << std::endl;
	{
		using namespace std;

		vector<int> vec;
		vector<int> vec1(10);
		vector<int> vec2(100, 1);

		cout << "real size: " << vec.size() << endl;
		cout << "real size: " << vec1.size() << endl;
		cout << "real size: " << vec2.size() << endl;
	}
	{
		using namespace ft;
	
		vector<int> vec;
		vector<int> vec1(10);
		vector<int> vec2(100, 1);

		std::cout << "my size:   " << vec.size() << std::endl;
		std::cout << "my size:   " << vec1.size() << std::endl;
		std::cout << "my size:   " << vec2.size() << std::endl;
	}
	std::cout << std::endl;
}

void vecMaxSizeTest(void) {
	std::cout << "-- Max_size --" << std::endl;
	{
		using namespace std;

		vector<int> vec;
		vector<char> vec1(10, 'a');
		vector<double> vec2(100, 42.42);

		cout << "real max_size: " << vec.max_size() << endl;
		cout << "real max_size: " << vec1.max_size() << endl;
		cout << "real max_size: " << vec2.max_size() << endl;
	}
	{
		using namespace ft;
	
		vector<int> vec;
		vector<char> vec1(10, 'a');
		vector<double> vec2(100, 42.42);

		std::cout << "my max_size:   " << vec.max_size() << std::endl;
		std::cout << "my max_size:   " << vec1.max_size() << std::endl; // get different result but same in linux
		std::cout << "my max_size:   " << vec2.max_size() << std::endl;
	}
	std::cout << std::endl;
}



// void test(void) {
// 	using namespace std;

// 	vector<int> vec(1, 1);
// 	vector<int> copy = vec;

// 	cout << vec[0] << endl;
// 	cout << copy[0] << endl;

// 	vec[0] = 2;
// 	cout << vec[0] << endl;
// 	cout << copy[0] << endl;
// }

int main(void) {
	vecSizeTest();
	vecMaxSizeTest();
	// test();

	return 0;
}