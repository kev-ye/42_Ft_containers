/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:16 by kaye              #+#    #+#             */
/*   Updated: 2021/09/22 16:14:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
       map<int, string> mapStudent;
       mapStudent.insert(pair<int, string>(1, "student_one"));
       mapStudent.insert(pair<int, string>(2, "student_two"));
       mapStudent.insert(pair<int, string>(3, "student_three"));
       map<int, string>::iterator  iter;
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
       {
            cout << iter->first << " " << iter->second << endl;
       }
       return 0;
}