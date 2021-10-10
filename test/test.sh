# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:35:38 by kaye              #+#    #+#              #
#    Updated: 2021/10/11 00:47:24 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Function

## Utils

printUsage() {
	echo -e "usage: bash test.sh [\033[1;32magrs\033[0m] or [\033[1;32mcontainers\033[0m] [\033[1;32mnamespace\033[0m]"
	echo -e "args1: \033[1;32mall\033[0m: launch all test"
	echo -e "       \033[1;32mclean\033[0m: clear deepthought/log directory and file"
	echo -e "args2: \033[1;32mcontainer\033[0m: (show diff + log) vector/stack/map"
	echo -e "       \033[1;32mnamespace(use with container)\033[0m: (show log) std/ft"
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
	if [ -d "./deepthought" ] ; then
		rm -rf deepthought
	fi

	if [ -d "./log" ] ; then
		rm -rf log
	fi

	for EN in 'Vec' 'Stack' 'Map'
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

vectorStdCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=std -o stdVec
}

vectorFtCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers vecTest.cpp -D __NS__=ft -o ftVec
}

vectorLog() {
	for VECTEST in 'constructTest' 'iteratorTest'
	do
		if [ -d "./log" ] && [ -f "./stdVec" ] ; then
			./stdVec $VECTEST > ./log/std_vec_"$VECTEST".log
		fi

		if [ -d "./log" ] && [ -f "./ftVec" ] ; then
			./ftVec $VECTEST > ./log/ft_vec_"$VECTEST".log
		fi
	done
}

vectorDiff() {
	for VECTEST in 'constructTest' 'iteratorTest'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_vec_"$VECTEST".log" ] && [ -f "./log/ft_vec_"$VECTEST".log" ] ; then
			diff ./log/std_vec_"$VECTEST".log ./log/ft_vec_"$VECTEST".log > ./deepthought/vec_"$VECTEST".diff
			if [ ! -s "$VECTEST".diff ] ; then
				echo -e ""$VECTEST" : \033[1;32mOk\033[0m"

			else
				echo -e ""$VECTEST" : \033[1;33mKo\033[0m"
				
			fi
		else
			echo -e "log file not found!"

		fi
	done
}

## Stack

stackStdCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers stackTest.cpp -D __NS__=std -o stdStack
}

stackFtCompile() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I../containers stackTest.cpp -D __NS__=ft -o ftStack
}

stackRun() {
	if [ -d "./log" ] && [ -f "./stdStack" ] ; then
		./stdStack constructTest > ./log/std_stack_constructTest.log
	fi

	if [ -d "./log" ] && [ -f "./ftStack" ] ; then
		./ftStack constructTest > ./log/ft_stack_constructTest.log
	fi
}

stackDiff() {
	if [ -d "./deepthought" ] && [ -f "./log/std_stack_constructTest.log" ] && [ -f "./log/ft_stack_constructTest.log" ] ; then
		diff ./log/std_stack_constructTest.log ./log/ft_stack_constructTest.log > ./deepthought/stack_constructTest.diff
		if [ ! -s constructTest.diff ] ; then
			echo -e "constructor test : \033[1;32mOk\033[0m"

		else
			echo -e "constructor test : \033[1;33mKo\033[0m"
			
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

	vectorRLog
	vectorDiff

elif [[ $1 = 'stack' ]] && [ -z $2 ] ; then
	cleanDeepthought
	createDeepthoughtDirectory

	stackStdCompile
	stackFtCompile

	stackRun
	stackDiff

elif [[ $1 = 'map' ]] && [ -z $2 ] ; then
	cleanDeepthought
	createDeepthoughtDirectory

	mapStdCompile
	mapFtCompile

	mapRun
	mapDiff

else
	printUsage

fi
