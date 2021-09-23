/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/09/23 16:58:03 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
       map<char, string> m;
       m.insert(pair<int, string>('a', "student_one"));
       m.insert(pair<int, string>('b', "student_two"));

       cout << m.size() << endl;
       return 0;
}