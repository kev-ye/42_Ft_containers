# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:35:38 by kaye              #+#    #+#              #
#    Updated: 2021/10/11 16:57:49 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Function

## Utils

printUsage() {
	echo -e "usage: bash test.sh [\033[1;32magrs\033[0m]"
	echo -e "args: \033[1;32mall\033[0m: launch all test"
	echo -e "      \033[1;32mclean\033[0m: clear deepthought/log directory and file"
	echo -e "      \033[1;32mcontainers\033[0m: vector/stack/map (diff + log)"
	echo -e "Tips: \033[1;35mYou can use the execute std/ft{containersNames} (after tester launch) to compare one by one\033[0m"
}

createDeepthoughtDirectory() {
	for DL in 'deepthought' 'log'
	do
		if [ ! -d "./$DL" ] ; then
			mkdir $DL
		fi
	done
}

cleanDeepthought() {
	for DL in 'deepthought' 'log'
	do
		if [ -d "./$DL" ] ; then
			rm -rf $DL
		fi
	done

	for EN in 'Vec' 'Stack' 'Map' 'Set'
	do
		for NS in 'std' 'ft'
		do
			if [ -f "./$NS$EN" ] ; then
				rm $NS$EN
			fi
		done
	done
}

## vector

vectorCompilation() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../containers ./srcs/vecTest.cpp -D __NS__=std -o stdVec
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../containers ./srcs/vecTest.cpp -D __NS__=ft -o ftVec
}

vectorTest() {
	for VECTEST in 'constructTest' 'iteratorTest' 'sizeTest' 'resizeTest' 'emptyTest' 'elementAccessTest' 'assignTest' 'pbTest' 'insertTest' 'eraseTest' 'swapTest' 'clear'
	do
		if [ -d "./log" ] && [ -f "./stdVec" ] ; then
			./stdVec $VECTEST > ./log/std_vec_"$VECTEST".log
		fi

		if [ -d "./log" ] && [ -f "./ftVec" ] ; then
			./ftVec $VECTEST > ./log/ft_vec_"$VECTEST".log
		fi
	done

	for VECTEST in 'constructTest' 'iteratorTest' 'sizeTest' 'resizeTest' 'emptyTest' 'elementAccessTest' 'assignTest' 'pbTest' 'insertTest' 'eraseTest' 'swapTest' 'clear'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_vec_"$VECTEST".log" ] && [ -f "./log/ft_vec_"$VECTEST".log" ] ; then
			diff ./log/std_vec_"$VECTEST".log ./log/ft_vec_"$VECTEST".log > ./deepthought/vec_"$VECTEST".diff
			if [ ! -s "./deepthought/vec_"$VECTEST".diff" ] ; then
				echo -e "$VECTEST : \033[1;32m[Ok]\033[0m"
				rm ./deepthought/vec_"$VECTEST"

			else
				echo -e ""$VECTEST" : \033[1;31m[Ko]\033[0m"
				
			fi
		else
			echo -e "log file not found!"

		fi
	done
}

# Run

createDeepthoughtDirectory

if [[ $1 = 'all' ]] && [ -z $2 ] ; then
	clear
	echo -e "coming soon ..."

elif [[ $1 = 'clean' ]] && [ -z $2 ] ; then
	cleanDeepthought

elif [[ $1 = 'vector' ]] && [ -z $2 ] ; then
	echo -e "\033[1;35mVector\033[0m"
	cleanDeepthought
	createDeepthoughtDirectory

	vectorCompilation
	vectorTest

elif [[ $1 = 'stack' ]] && [ -z $2 ] ; then
	echo -e "\033[1;35mStack\033[0m"
	cleanDeepthought
	createDeepthoughtDirectory

	stackCompilation
	stackTest

elif [[ $1 = 'map' ]] && [ -z $2 ] ; then
	echo -e "\033[1;35mMap\033[0m"
	cleanDeepthought
	createDeepthoughtDirectory

	mapCompilation
	mapTest

elif [[ $1 = 'set' ]] && [ -z $2 ] ; then
	echo -e "\033[1;35mSet\033[0m"
	cleanDeepthought
	createDeepthoughtDirectory

	setCompilation
	setTest

else
	printUsage

fi
