/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/09/13 19:57:43 by kaye             ###   ########.fr       */
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

void vecReserveTest(void) {
{
	using namespace std;

	vector<int> vec(10);

	cout << "-- real --" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;

	vec.reserve(1);
	cout << "--> reserve 1" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;
	
	vec.reserve(20);
	cout << "--> reserve 20" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;

	cout << endl;

}
{
	using namespace ft;

	vector<int> vec(10);

	std::cout << "-- my --" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;

	vec.reserve(1);
	std::cout << "--> reserve 1" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;
	
	vec.reserve(20);
	std::cout << "--> reserve 20" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;
}
}

// void test(void) {
// {
// 	using namespace std;

// 	vector<int> vec(10);

// 	cout << "-- real --" << endl;

// 	cout << "size: " << vec.size() << endl;
// 	cout << "cap: " << vec.capacity() << endl;

// 	vec.reserve(1);
// 	cout << "reserve 1" << endl;

// 	cout << "size: " << vec.size() << endl;
// 	cout << "cap: " << vec.capacity() << endl;
	
// 	vec.reserve(20);
// 	cout << "reserve 20" << endl;

// 	cout << "size: " << vec.size() << endl;
// 	cout << "cap: " << vec.capacity() << endl;

// 	// vec.resize(10);
// 	// cout << "size: " << vec.size() << endl;
// 	// cout << "cap: " << vec.capacity() << endl;
// 	// cout << "element [5]: " << vec[5] << endl;

// 	// vec.reserve(20);
// 	// cout << "size: " << vec.size() << endl;
// 	// cout << "cap: " << vec.capacity() << endl;
// 	// cout << "element [15]: " << vec[15] << endl;

// 	cout << endl;

// }
// // {
// // 	using namespace ft;

// // 	vector<int> vec(10);

// // 	std::cout << "-- my --" << std::endl;

// // 	std::cout << "size: " << vec.size() << std::endl;
// // 	std::cout << "cap: " << vec.capacity() << std::endl;

// // 	vec.clear();

// // 	std::cout << "size: " << vec.size() << std::endl;
// // 	std::cout << "cap: " << vec.capacity() << std::endl;
// // }
// }

int main(void) {
	// vecSizeTest();
	// vecMaxSizeTest();
	vecReserveTest();
	// test();

	return 0;
}