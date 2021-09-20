	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:27 by kaye              #+#    #+#             */
/*   Updated: 2021/09/17 14:10:30 by kaye             ###   ########.fr       */
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
	using namespace std;

	cout << "-- Size --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec;
	std::vector<int> vec1(10);
	std::vector<int> vec2(100, 1);

	cout << "real size: " << vec.size() << endl;
	cout << "real size: " << vec1.size() << endl;
	cout << "real size: " << vec2.size() << endl;
	cout << endl;
}

void vecMaxSizeTest(void) {
	using namespace std;

	cout << "-- Max_size --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec;
	std::vector<char> vec1(10, 'a');
	std::vector<double> vec2(100, 42.42);

	cout << "real max_size: " << vec.max_size() << endl;
	cout << "real max_size: " << vec1.max_size() << endl;
	cout << "real max_size: " << vec2.max_size() << endl;

	cout << endl;
}

void vecResizeTest(void) {
	using namespace std;

	cout << "-- Resize --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(10, 0);

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

void vecReserveTest(void) {
	using namespace std;

	cout << "-- Reserve --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(10);

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

void vecAccess(void) {
	using namespace std;

	cout << "-- Access --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(10, 100);
	

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

void vecAssignTest(void) {
	using namespace std;

	cout << "-- Assign --" << endl;
	cout << "-- real --\n" << endl;
	cout << "-- fill --\n" << endl;

	std::vector<int> vec(10, 999);
	std::vector<int> vec1;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);

	cout << "size befor assign: " << vec.size() << endl;
	cout << "cap befor assign: " << vec.capacity() << endl << endl;

	vec.assign(4, 10);

	cout << "size after assign: " << vec.size() << endl;
	cout << "cap after assign: " << vec.capacity() << endl;

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	for (; it != ite; it++)
		cout << *it << " ";

	cout << endl << endl;

	cout << "-- range --\n" << endl;
	std::vector<int> vec2;

	vec2.push_back(10);
	vec2.push_back(20);

	vec.assign(vec2.begin(), vec2.end());

	cout << "size after assign: " << vec.size() << endl;
	cout << "cap after assign: " << vec.capacity() << endl;

	it = vec.begin();
	ite = vec.end();

	for (; it != ite; it++)
		cout << *it << " ";

	cout << endl << endl;
}

void vecPushPopTest(void) {
	using namespace std;

	cout << "-- Push/Pop --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(5);


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

void vecSwapTest(void) {
	using namespace std;

	cout << "-- Swap --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(5, 100);
	std::vector<int> vec2(10, 999);

	cout << "size before swap: vec: " << vec.size() << endl;
	cout << "cap before swap: vec: " << vec.capacity() << endl;
	cout << "first: " << vec.front() << endl;
	cout << "back: " << vec.back() << endl;

	cout << "size before swap: vec2: " << vec2.size() << endl;
	cout << "cap before swap: vec2: " << vec2.capacity() << endl;
	cout << "first: " << vec2.front() << endl;
	cout << "back: " << vec2.back() << endl;

	cout << endl;

	vec.swap(vec2);

	cout << "size after swap: vec: " << vec.size() << endl;
	cout << "cap after swap: vec: " << vec.capacity() << endl;
	cout << "first: " << vec.front() << endl;
	cout << "back: " << vec.back() << endl;

	cout << "size after swap: vec2: " << vec2.size() << endl;
	cout << "cap after swap: vec2: " << vec2.capacity() << endl;
	cout << "first: " << vec2.front() << endl;
	cout << "back: " << vec2.back() << endl;

	cout << endl;

	swap(vec, vec2);

	cout << "size after swap: vec: " << vec.size() << endl;
	cout << "cap after swap: vec: " << vec.capacity() << endl;
	cout << "first: " << vec.front() << endl;
	cout << "back: " << vec.back() << endl;

	cout << "size after swap: vec2: " << vec2.size() << endl;
	cout << "cap after swap: vec2: " << vec2.capacity() << endl;
	cout << "first: " << vec2.front() << endl;
	cout << "back: " << vec2.back() << endl;

	cout << endl;
}

void vecAssignment(void) {
	using namespace std;

	cout << "-- Assignment --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec(4, 2);
	std::vector<int> vec2(vec);
	vec.pop_back();

	cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << endl;
	cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << endl;

	vec[0] = 1;
	cout << "vec: " << vec[0] << " - cap: " << vec.capacity() << endl;
	cout << "vec2: " << vec2[0] << " - cap: " << vec2.capacity() << endl;

	cout << endl;
}

void vecEraseTest(void) {
	using namespace std;

	cout << "-- Erase --" << endl;
	cout << "-- real --\n" << endl;

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "size bfr assig: " << vec.size() << endl;
	cout << "cap bfr assig:  " << vec.capacity() << endl;

	vec.erase(vec.begin() + 2);

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();;

	cout << "\nsize aft assig: " << vec.size() << endl;
	cout << "cap aft assig:  " << vec.capacity() << endl;

	for (; it != ite; it++)
		cout << *it << " ";

	cout << endl << endl;
}

void vecConstItTest(void) {
	using namespace std;

	cout << "-- Const It --" << endl;

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	std::vector<int>::const_reverse_iterator crit(ite);

	std::vector<int>::const_reverse_iterator crite(it);

	if (crit < crite)
		cout << "true\n";
}

void vecInsertTest(void) {
	using namespace std;

	cout << "-- Insert --" << endl;

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	vec.pop_back();

	cout << "size bfr insert: " << vec.size() << endl;
	cout << "cap bfr insert:  " << vec.capacity() << endl << endl;

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	it = vec.insert(ite, 100);

	it = vec.begin();
	ite = vec.end();

	cout << "size aft insert: " << vec.size() << endl;
	cout << "cap aft insert:  " << vec.capacity() << endl << endl;

	for(; it != ite; it++)
		cout << *it << " ";
	cout << endl;
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
	// vecSwapTest();
	// vecAssignment();
	// vecEraseTest();
	// vecConstItTest();
	vecInsertTest();

	// using namespace std;

	// std::vector<int> vec;

	// vec.push_back(1);
	// vec.push_back(2);
	// vec.push_back(3);
	// vec.push_back(4);

	// std::vector<int>::iterator it = vec.begin();

	// vec.erase(it + 1);

	// it = vec.begin();
	// std::vector<int>::iterator ite = vec.end();

	// for (; it != ite; it++ )
	// 				std::cout << *it << " ";
	// 			std::cout << std::endl;

	return 0;
}