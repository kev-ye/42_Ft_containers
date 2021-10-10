# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:35:38 by kaye              #+#    #+#              #
#    Updated: 2021/10/10 18:59:55 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Function

printUse() {
	echo -e "use: ./test.sh [\e[1;32margs\e[0m]"
	echo -e "args: \e[1;32mstd\e[0m: compile test with std"
	echo -e "      \e[1;32mft\e[0m: compile test with ft"
	echo -e "      \e[1;32mcomp\e[0m: show difference between std and ft"
	echo -e "      \e[1;32mclean\e[0m: clear deepthought/log directory and file"
}

createDeepthought() {
	if [ ! -d "./deepthought" ] ; then
		mkdir deepthought
	fi

	if [ ! -d "./log" ] ; then
		mkdir log
	fi
}

cleanDeepthought() {
	if [ -d "./deepthought" ] ; then
		rm -rf deepthought
	fi

	if [ -d "./log" ] ; then
		rm -rf log
	fi
}

runStdCase() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=std
	./a.out && rm a.out 2>/dev/null
}

runFtCase() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=ft
	./a.out && rm a.out 2>/dev/null
}

doDeepthought() {
	runStdCase > ./log/stdCase
	runFtCase > ./log/FtCase

	diff ./log/stdCase ./log/FtCase > ./deepthought/df
}

# Run

createDeepthought

if [[ $1 = 'std' ]] ; then
	clear
	echo -e "\e[1;32mstd case:\e[0m"
	runStdCase

elif [[ $1 = 'ft' ]] ; then
	clear
	echo -e "\e[1;32mstd case:\e[0m"
	runFtCase

elif [[ $1 = 'comp' ]] ; then
	clear
	cleanDeepthought
	createDeepthought
	doDeepthought

elif [[ $1 = 'clean' ]] ; then
	cleanDeepthought
	
else
	printUse

fi
