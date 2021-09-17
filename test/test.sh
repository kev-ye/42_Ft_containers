# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:35:38 by kaye              #+#    #+#              #
#    Updated: 2021/09/17 18:29:53 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ $1 = 'r' ] ; then
	clear
	rm a.out 2>/dev/null
	clang++ -std=c++98 ../containers/main.cpp
	./a.out
	
	rm a.out 2>/dev/null
elif [ $1 = 'm' ] ; then
	rm a.out 2>/dev/null
	clear
	clang++ -std=c++98 creatFile.cpp -o replace
	./replace ../containers/main.cpp tmp.cpp "std::" "ft::"
	./replace tmp.cpp mytest.cpp "real" "my"
	rm tmp.cpp 2>/dev/null

	rm replace 2>/dev/null
	clang++ -std=c++98 -I../containers/ mytest.cpp
	./a.out

	rm mytest.cpp 2>/dev/null
	rm a.out 2>/dev/null
fi