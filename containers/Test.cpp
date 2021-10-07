/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/07 19:55:14 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

#include <list>

using namespace std;

#define _pair std::pair

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) cout << "~foo::foo()" << endl; };
		void m(void) { cout << "foo::m called [" << this->value << "]" << endl; };
		void m(void) const { cout << "foo::m const called [" << this->value << "]" << endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				cout << "foo::operator=(foo) CALLED" << endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
ostream	&operator<<(ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

template <typename T>
string	printPair(const T &iterator, bool nl = true, ostream &o = cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << endl;
	return ("");
}


template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	cout << "size: " << mp.size() << endl;
	cout << "max_size: " << mp.max_size() << endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		cout << endl << "Content is:" << endl;
		for (; it != ite; ++it)
			cout << "- " << printPair(it, false) << endl;
	}
	cout << "###############################################" << endl;
}

#define T1 int
#define T2 foo<int>
typedef std::map<T1, T2>::value_type T3;
typedef std::map<T1, T2>::iterator ft_iterator;
typedef std::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const int &param)
{
	ft_const_iterator ite = mp.end();
	ft_const_iterator it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	cout << "\t-- [" << iter++ << "] --" << endl;
	cout << "with key [" << param << "]:" << endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << endl;
	cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << endl;
	// cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << endl;
}

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	cout << "\t-- [" << iter++ << "] (const) --" << endl;
// 	cout << "with key [" << param << "]:" << endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << endl;
// 	cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << endl;
// 	cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << endl;
// }

int main(void) {
	using namespace std;

	// list<T3> lst;
	// unsigned int lst_size = 10;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(T3(i + 1, (i + 1) * 3));
	// std::map<T1, T2> mp(lst.begin(), lst.end());
	// printSize(mp);

	std::map<int, int> m;

	m[1] = 1;
	m[2] = 2;

	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> p;

	std::map<int, int>::const_iterator it1 = m.lower_bound(1);
	std::map<int, int>::const_iterator it2 = m.upper_bound(1);

	p = m.equal_range(1);

	cout << "pf: " << p.first->first << endl;
	cout << "ps: " <<p.second->first << endl;

	cout << "it1: " << it1->first << endl;
	cout << "it2: " << it2->first << endl;

	if (p.first == it1) // PB HERE
		cout << "ok\n";

	// // ft_const_bound(mp, -10);
	// // ft_const_bound(mp, 1);
	// // ft_const_bound(mp, 5);
	// // ft_const_bound(mp, 10);
	// // ft_const_bound(mp, 50);

	// printSize(mp);

	// mp.lower_bound(3)->second = 404;
	// mp.upper_bound(7)->second = 842;

	// ft_bound(mp, 5);
	// ft_bound(mp, 7);

	// mymap['b'] = 100;
	// mymap['a'] = 200;  
	// mymap['c'] = 300;

	// // show content:
	// std::map<char, int>::const_iterator it = mymap.begin();
	// std::map<char, int>::const_iterator cit = mymap.begin();

	// if (it == cit)
	// 	cout << "ok\n";
	// else
	// 	cout << "nope\n";

	// for (; it != mymap.end(); it++)
	// 	cout << it->first << endl;
	return 0;
}