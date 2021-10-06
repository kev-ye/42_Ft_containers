/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/10/06 20:12:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

int main(void) {
	using namespace std;

	// std::map<char,int> foo,bar;
	// foo['a']=100;
	// foo['b']=200;
	// bar['a']=10;
	// bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	// if (foo==bar) cout << "foo and bar are equal\n";
	// if (foo!=bar) cout << "foo and bar are not equal\n";
	// if (foo< bar) cout << "foo is less than bar\n";
	// if (foo> bar) cout << "foo is greater than bar\n";
	// if (foo<=bar) cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) cout << "foo is greater than or equal to bar\n";

	// cout << foo.size() << endl;

	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it = mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		cout << it->first << " => " << it->second << '\n';

	return 0;
}