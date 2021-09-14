/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/09/14 19:44:44 by kaye             ###   ########.fr       */
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

void vecResizeTest(void) {
{
	using namespace std;

	vector<int> vec(10, 0);

	cout << "-- real --" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;

	vec.resize(1, 10);
	cout << "--> resize 1, 10" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;
	
	vec.resize(20, 100);
	cout << "--> resize 20, 100" << endl;

	cout << "size: " << vec.size() << endl;
	cout << "cap: " << vec.capacity() << endl;

	cout << endl;

}
{
	using namespace ft;

	vector<int> vec(10, 0);

	std::cout << "-- my --" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;

	vec.resize(1, 10);
	std::cout << "--> reserve 1" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;
	
	vec.resize(20, 100);
	std::cout << "--> reserve 20" << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "cap: " << vec.capacity() << std::endl;
}
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

void vecAccess(void) {
	std::cout << "-- Max_size --" << std::endl;
{
	using namespace std;

	vector<int> vec(10, 100);
	
	cout << "-- real --" << endl;
	cout << "[0]: " << vec[0] << endl;
	cout << "[9]: " << vec[9] << endl;

	cout << "at(0): " << vec.at(0) << endl;
	vec.at(9) = 99;
	cout << "at(9): " << vec.at(9) << endl;
	// cout << "at(10): " << vec.at(10) << endl; // exception

	cout << "front: " << vec.front() << endl;
	cout << "back: " << vec.back() << endl;

	cout << endl;
}
{
	using namespace ft;

	vector<int> vec(10, 100);
	
	std::cout << "-- my --" << std::endl;
	std::cout << "[0]: " << vec[0] << std::endl;
	std::cout << "[9]: " << vec[9] << std::endl;

	std::cout << "at(0): " << vec.at(0) << std::endl;
	vec.at(9) = 99;
	std::cout << "at(9): " << vec.at(9) << std::endl;
	// std::cout << "at(10): " << vec.at(10) << std::endl; // exception

	std::cout << "front: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;
}
}

void relationalOperator(void) {
{
	using namespace std;

	vector<int> vec(1, 1);
	vector<int> vec2(1, 2);

	cout << std::boolalpha << "vec == vec2: "<< (vec == vec2) << endl;

	cout << endl;
}
// {
// 	using namespace ft;

// 	vector<int> vec(1, 1);
// 	vector<int> vec2(1, 2);

// 	std::cout << std::boolalpha << (vec == vec2) << std::endl;
// }
}

void vecAssignTest(void) {
{
	using namespace std;

	vector<int> vec(10, 999);
	
	cout << "-- real --" << endl;

	cout << "size befor assign: " << vec.size() << endl;
	cout << "cap befor assign: " << vec.capacity() << endl;

	vec.assign(7, 100);

	cout << "size after assign: " << vec.size() << endl;
	cout << "cap after assign: " << vec.capacity() << endl;

	cout << "[0]: " << vec[0] << endl;
	cout << "[6]: " << vec[6] << endl;

	cout << endl;
}
{
	using namespace ft;

	vector<int> vec(10);

	std::cout << "-- my --" << std::endl;
	
	std::cout << "size befor assign: " << vec.size() << std::endl;
	std::cout << "cap befor assign: " << vec.capacity() << std::endl;

	vec.assign(7, 100);

	std::cout << "size after assign: " << vec.size() << std::endl;
	std::cout << "cap after assign: " << vec.capacity() << std::endl;

	std::cout << "[0]: " << vec[0] << std::endl;
	std::cout << "[6]: " << vec[6] << std::endl;
}
}

void vecPushPopTest(void) {
{
	using namespace std;

	vector<int> vec(5);
	
	cout << "-- real --" << endl;

	cout << "size befor push: " << vec.size() << endl;
	cout << "cap befor push: " << vec.capacity() << endl;

	vec.push_back(1);
	vec.push_back(2);

	cout << "size after push: " << vec.size() << endl;
	cout << "cap after push: " << vec.capacity() << endl;
	cout << "[5]: " << vec[5] << endl;
	cout << "[6]: " << vec[6] << endl;

	vec.pop_back();
	cout << "size after pop: " << vec.size() << endl;
	cout << "cap after pop: " << vec.capacity() << endl;
	cout << "last: " << vec.back() << endl;

	cout << endl;
}
{
	using namespace ft;

	vector<int> vec(5);
	
	std::cout << "-- my --" << std::endl;

	std::cout << "size befor push: " << vec.size() << std::endl;
	std::cout << "cap befor push: " << vec.capacity() << std::endl;

	vec.push_back(1);
	vec.push_back(2);

	std::cout << "size after push: " << vec.size() << std::endl;
	std::cout << "cap after push: " << vec.capacity() << std::endl;
	std::cout << "[5]: " << vec[5] << std::endl;
	std::cout << "[6]: " << vec[6] << std::endl;

	vec.pop_back();
	std::cout << "size after pop: " << vec.size() << std::endl;
	std::cout << "cap after pop: " << vec.capacity() << std::endl;
	std::cout << "last: " << vec.back() << std::endl;
}
}

void vecSwapTest(void) {
{
	using namespace std;

	vector<int> vec(5, 100);
	vector<int> vec2(10, 999);

	std::cout << "-- real --" << std::endl;

	std::cout << "size before swap: vec: " << vec.size() << std::endl;
	std::cout << "cap before swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size before swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap before swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;

	cout << endl;

	vec.swap(vec2);

	std::cout << "size after swap: vec: " << vec.size() << std::endl;
	std::cout << "cap after swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size after swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap after swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;

	cout << endl;

	swap(vec, vec2);

	std::cout << "size after swap: vec: " << vec.size() << std::endl;
	std::cout << "cap after swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size after swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap after swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;

	cout << endl;
}
{
	using namespace ft;

	vector<int> vec(5, 100);
	vector<int> vec2(10, 999);

	std::cout << "-- my --" << std::endl;

	std::cout << "size before swap: vec: " << vec.size() << std::endl;
	std::cout << "cap before swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size before swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap before swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;

	std::cout << std::endl;

	vec.swap(vec2);

	std::cout << "size after swap: vec: " << vec.size() << std::endl;
	std::cout << "cap after swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size after swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap after swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;

	std::cout << std::endl;

	swap(vec, vec2);

	std::cout << "size after swap: vec: " << vec.size() << std::endl;
	std::cout << "cap after swap: vec: " << vec.capacity() << std::endl;
	std::cout << "first: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	std::cout << "size after swap: vec2: " << vec2.size() << std::endl;
	std::cout << "cap after swap: vec2: " << vec2.capacity() << std::endl;
	std::cout << "first: " << vec2.front() << std::endl;
	std::cout << "back: " << vec2.back() << std::endl;
}
}

void vecAssignment(void) {
{
	std::cout << "-- real --" << std::endl;

	using namespace std;

	vector<int> vec(4, 2);
	vector<int> vec2(vec);
	vec.pop_back();

	std::cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << std::endl;
	std::cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << std::endl;

	vec[0] = 1;
	std::cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << std::endl;
	std::cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << std::endl;

	std::cout << std::endl;
}
{
	std::cout << "-- my --" << std::endl;

	using namespace ft;

	vector<int> vec(4, 2);
	vector<int> vec2(vec);
	vec.pop_back();

	std::cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << std::endl;
	std::cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << std::endl;

	vec[0] = 1;
	std::cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << std::endl;
	std::cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << std::endl;;
}
}

int main(void) {
	// vecSizeTest();
	// vecMaxSizeTest();
	// vecResizeTest();
	// vecReserveTest();
	// vecAccess();
	// relationalOperator();
	// vecAssignTest();
	// vecPushPopTest();
	vecSwapTest();
	// vecAssignment();

	return 0;
}