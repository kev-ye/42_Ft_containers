/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/08 20:59:20 by kaye             ###   ########.fr       */
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
#define T2 string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	cout << "\t-- [" << iter++ << "] --" << endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	cout << "\t-- [" << iter++ << "] --" << endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, string((lst_size - i), i + 65)));
	std::map<T1, T2> mp(lst.begin(), lst.end());
	// printSize(mp);

	// ft_erase(mp, ++mp.begin());

	// ft_erase(mp, mp.begin());
	// ft_erase(mp, --mp.end());

	// ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	// ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";

	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}
