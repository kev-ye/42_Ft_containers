# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:35:38 by kaye              #+#    #+#              #
#    Updated: 2021/10/10 20:25:22 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Function

## Utils

printUse() {
	echo -e "usage: bash test.sh [\e[1;32magrs\e[0m] or [\e[1;32mcontainers\e[0m] [\e[1;32mnamespace\e[0m]"
	echo -e "args1: \e[1;32mall\e[0m: launch all test"
	echo -e "       \e[1;32mclean\e[0m: clear deepthought/log directory and file"
	echo -e "args2: \e[1;32mcontainer\e[0m: (show diff + log) vector/stack/map"
	echo -e "       \e[1;32mnamespace(use with container)\e[0m: (show log) std/ft"
}

createDeepthoughtDirectory() {
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

	if [ -f "./stdVec" ] ; then
		rm stdVec
	fi

	if [ -f "./ftVec" ] ; then
		rm ftVec
	fi
}

## vector

vectorStdCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=std -o stdVec
}

vectorFtCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=ft -o ftVec
}

vectorRun() {
	if [ -d "./log" ] && [ -f "./stdVec" ] ; then
		./stdVec constructTest > ./log/std_constructTest.log
	fi

	if [ -d "./log" ] && [ -f "./ftVec" ] ; then
		./ftVec constructTest > ./log/ft_constructTest.log
	fi
}

vectorDiff() {
	if [ -d "./deepthought" ] && [ -f "./log/std_constructTest.log" ] && [ -f "./log/ft_constructTest.log" ] ; then
		diff ./log/std_constructTest.log ./log/ft_constructTest.log > ./deepthought/constructTest.diff
		if [ ! -s constructTest.diff ] ; then
			echo -e "constructor test : \e[1;32mOk\e[0m"

		else
			echo -e "constructor test : \e[1;33mKo\e[0m"
			
		fi
	else
		echo -e "log file not found!"

	fi
}

# Run

createDeepthoughtDirectory

if [[ $1 = 'all' ]] && [ -z $2 ] ; then
	clear
	echo -e "coming soon ..."

elif [[ $1 = 'clean' ]] && [ -z $2 ] ; then
	cleanDeepthought

elif [[ $1 = 'vector' ]] && [ -z $2 ] ; then
	cleanDeepthought
	createDeepthoughtDirectory

	vectorStdCompile
	vectorFtCompile

	vectorRun
	vectorDiff

elif [[ $1 = 'vector' ]] && ([ $2 = 'std' ] || [ $2 = 'ft' ]) && [ -z $3 ]; then
	if [ $2 = 'std' ] ; then
		clear
		echo "std case"
		cleanDeepthought
		createDeepthoughtDirectory

	elif [ $2 = 'ft' ] ; then
		clear
		echo "ft case"
		cleanDeepthought
		createDeepthoughtDirectory

	fi
	
else
	printUse

fi
