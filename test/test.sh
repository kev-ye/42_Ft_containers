#!/bin/bash

CONTAINERS_FOLDER=containers

# Function

## Utils

printUsage() {
	echo -e "usage: ./test.sh [\033[1;32magrs\033[0m]"
	echo -e "args: \033[1;32mall\033[0m: launch all test"
	echo -e "      \033[1;32mclean\033[0m: clear deepthought/log directory and file"
	echo -e "      \033[1;32mtime\033[0m: show run time"
	echo -e "      \033[1;32mcontainers\033[0m: vector/stack/map/set (diff + log)"
	echo -e "Tips: \033[1;35mChanger the path in test.sh with 'CONTAINERS_FOLDER'\033[0m"
	echo -e "Tips2: \033[1;35mYou can use the execute std/ft{containersNames} (after tester launch) to compare one by one\033[0m"
}

createDeepthoughtDirectory() {
	for DL in 'deepthought' 'log'
	do
		if [ ! -d "./$DL" ] ; then
			mkdir $DL
		fi
	done
}

cleanAll() {
	for DL in 'deepthought' 'log'
	do
		if [ -d "./$DL" ] ; then
			rm -rf $DL
		fi
	done

	for EN in 'Vec' 'Stk' 'Map' 'Set'
	do
		for NS in 'std' 'ft'
		do
			if [ -f "./$NS$EN" ] ; then
				rm $NS$EN
			fi
		done
	done

	for RT in 'VecRunTime' 'StkRunTime' 'MapRunTime' 'SetRunTime'
	do
		for NS in 'std' 'ft'
		do
			if [ -f "./$NS$RT" ] ; then
				rm $NS$RT
			fi
		done
	done
}

remake() {
	cleanAll
	createDeepthoughtDirectory
}

## vector

vectorCompilation() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/vecTest.cpp -D __NS__=std -o stdVec
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/vecTest.cpp -D __NS__=ft -o ftVec
}

vectorTest() {
	for VECTEST in 'constructTest' 'iteratorTest' 'sizeTest' 'resizeTest' 'emptyTest' 'elementAccessTest' 'assignTest' 'pbTest' 'insertTest' 'eraseTest' 'swapTest' 'clear'
	do
		if [ -d "./log" ] && [ -f "./stdVec" ] ; then
			./stdVec $VECTEST > ./log/std_vec_"$VECTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi

		if [ -d "./log" ] && [ -f "./ftVec" ] ; then
			./ftVec $VECTEST > ./log/ft_vec_"$VECTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi
	done

	for VECTEST in 'constructTest' 'iteratorTest' 'sizeTest' 'resizeTest' 'emptyTest' 'elementAccessTest' 'assignTest' 'pbTest' 'insertTest' 'eraseTest' 'swapTest' 'clear'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_vec_"$VECTEST".log" ] && [ -f "./log/ft_vec_"$VECTEST".log" ] ; then
			diff ./log/std_vec_"$VECTEST".log ./log/ft_vec_"$VECTEST".log > ./deepthought/vec_"$VECTEST".diff
			if [ ! -s "./deepthought/vec_"$VECTEST".diff" ] ; then
				echo -e "$VECTEST : \033[1;32m[Ok]\033[0m"
				rm ./deepthought/vec_"$VECTEST".diff

			else
				echo -e ""$VECTEST" : \033[1;31m[Ko]\033[0m"
				
			fi
		else
			echo -e "\033[1;31mlog file not found!\033[0m"
			exit

		fi
	done
}

vectorRunTime() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/vecRunTime.cpp -D __NS__=std -o stdVecRunTime
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/vecRunTime.cpp -D __NS__=ft -o ftVecRunTime

	echo -e "\033[1;32mVector: STD part:\033[0m"
	time ./stdVecRunTime
	echo -e "\n\033[1;32mVector: FT part:\033[0m"
	time ./ftVecRunTime
}

## stack

stackCompilation() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/stackTest.cpp -D __NS__=std -o stdStk
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/stackTest.cpp -D __NS__=ft -o ftStk
}

stackTest() {
	for STKTEST in 'constructTest' 'emptyTest' 'sizeTest' 'topTest' 'pbTest'
	do
		if [ -d "./log" ] && [ -f "./stdStk" ] ; then
			./stdStk $STKTEST > ./log/std_stack_"$STKTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi

		if [ -d "./log" ] && [ -f "./ftStk" ] ; then
			./ftStk $STKTEST > ./log/ft_stack_"$STKTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi
	done

	for STKTEST in 'constructTest' 'emptyTest' 'sizeTest' 'topTest' 'pbTest'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_stack_"$STKTEST".log" ] && [ -f "./log/ft_stack_"$STKTEST".log" ] ; then
			diff ./log/std_stack_"$STKTEST".log ./log/ft_stack_"$STKTEST".log > ./deepthought/stack_"$STKTEST".diff
			if [ ! -s "./deepthought/stack_"$STKTEST".diff" ] ; then
				echo -e "$STKTEST : \033[1;32m[Ok]\033[0m"
				rm ./deepthought/stack_"$STKTEST".diff

			else
				echo -e ""$STKTEST" : \033[1;31m[Ko]\033[0m"
				
			fi
		else
			echo -e "log file not found!"
			exit

		fi
	done
}

stackRunTime() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/stackRunTime.cpp -D __NS__=std -o stdStkRunTime
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/stackRunTime.cpp -D __NS__=ft -o ftStkRunTime

	echo -e "\033[1;32mStack: STD part:\033[0m"
	time ./stdStkRunTime
	echo -e "\n\033[1;32mStack: FT part:\033[0m"
	time ./ftStkRunTime
	echo ""
}

## map

mapCompilation() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/mapTest.cpp -D __NS__=std -o stdMap
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/mapTest.cpp -D __NS__=ft -o ftMap
}

mapTest() {
	for MAPTEST in 'constructTest' 'iteratorTest' 'emptyTest' 'sizeTest' 'elementAccessTest' 'insertTest' 'eraseTest' 'swapTest' 'clearTest' 'keyCompTest' 'valueCompTest' 'findTest' 'countTest' 'boundTest' 'equalRangeTest'
	do
		if [ -d "./log" ] && [ -f "./stdMap" ] ; then
			./stdMap $MAPTEST > ./log/std_map_"$MAPTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi

		if [ -d "./log" ] && [ -f "./ftMap" ] ; then
			./ftMap $MAPTEST > ./log/ft_map_"$MAPTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi
	done

	for MAPTEST in 'constructTest' 'iteratorTest' 'emptyTest' 'sizeTest' 'elementAccessTest' 'insertTest' 'eraseTest' 'swapTest' 'clearTest' 'keyCompTest' 'valueCompTest' 'findTest' 'countTest' 'boundTest' 'equalRangeTest'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_map_"$MAPTEST".log" ] && [ -f "./log/ft_map_"$MAPTEST".log" ] ; then
			diff ./log/std_map_"$MAPTEST".log ./log/ft_map_"$MAPTEST".log > ./deepthought/map_"$MAPTEST".diff
			if [ ! -s "./deepthought/map_"$MAPTEST".diff" ] ; then
				echo -e "$MAPTEST : \033[1;32m[Ok]\033[0m"
				rm ./deepthought/map_"$MAPTEST".diff

			else
				echo -e ""$MAPTEST" : \033[1;31m[Ko]\033[0m"
			fi
		else
			echo -e "log file not found!"
			exit

		fi
	done
}

mapRunTime() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/mapRunTime.cpp -D __NS__=std -o stdMapRunTime
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/mapRunTime.cpp -D __NS__=ft -o ftMapRunTime

	echo -e "\033[1;32mMap: STD part:\033[0m"
	time ./stdMapRunTime
	echo -e "\n\033[1;32mMap: FT part:\033[0m"
	time ./ftMapRunTime
	echo ""
}

## set

setCompilation() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/setTest.cpp -D __NS__=std -o stdSet
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/setTest.cpp -D __NS__=ft -o ftSet
}

setTest() {
	for SETTEST in 'constructTest' 'iteratorTest' 'emptyTest' 'sizeTest' 'insertTest' 'eraseTest' 'swapTest' 'clearTest' 'keyCompTest' 'valueCompTest' 'findTest' 'countTest' 'boundTest' 'equalRangeTest'
	do
		if [ -d "./log" ] && [ -f "./stdSet" ] ; then
			./stdSet $SETTEST > ./log/std_set_"$SETTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi

		if [ -d "./log" ] && [ -f "./ftSet" ] ; then
			./ftSet $SETTEST > ./log/ft_set_"$SETTEST".log
		else
			echo -e "\033[1;31mlog folder or execute file not found!\033[0m"
			exit
		fi
	done

	for SETTEST in 'constructTest' 'iteratorTest' 'emptyTest' 'sizeTest' 'insertTest' 'eraseTest' 'swapTest' 'clearTest' 'keyCompTest' 'valueCompTest' 'findTest' 'countTest' 'boundTest' 'equalRangeTest'
	do
		if [ -d "./deepthought" ] && [ -f "./log/std_set_"$SETTEST".log" ] && [ -f "./log/ft_set_"$SETTEST".log" ] ; then
			diff ./log/std_set_"$SETTEST".log ./log/ft_set_"$SETTEST".log > ./deepthought/set_"$SETTEST".diff
			if [ ! -s "./deepthought/set_"$SETTEST".diff" ] ; then
				echo -e "$SETTEST : \033[1;32m[Ok]\033[0m"
				rm ./deepthought/set_"$SETTEST".diff

			else
				echo -e ""$SETTEST" : \033[1;31m[Ko]\033[0m"
				
			fi
		else
			echo -e "log file not found!"
			exit

		fi
	done
}

setRunTime() {
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/setRunTime.cpp -D __NS__=std -o stdSetRunTime
	clang++ -Wall -Wextra -Werror -std=c++98 -I./inc -I../$CONTAINERS_FOLDER ./srcs/setRunTime.cpp -D __NS__=ft -o ftSetRunTime

	echo -e "\033[1;32mSet: STD part:\033[0m"
	time ./stdSetRunTime
	echo -e "\n\033[1;32mSet: FT part:\033[0m"
	time ./ftSetRunTime
}

# Run

createDeepthoughtDirectory

if [[ $1 = 'all' ]] && [ -z $2 ] ; then
	clear
	remake

	for CONT in 'vector' 'stack' 'map' 'set'
	do
		echo -e "\033[1;35m$CONT\033[0m"
		$CONT"Compilation"
		$CONT"Test"
		if [[ $CONT != 'set' ]] ; then
			echo ""
		fi
	done

elif [[ $1 = 'clean' ]] && [ -z $2 ] ; then
	clear
	cleanAll

elif [[ $1 = 'time' ]] && [ -z $2 ] ; then
	clear
	
	for CONT in 'vector' 'stack' 'map' 'set'
	do
		$CONT"RunTime"
	done


elif [[ $1 = 'vector' ]] && [ -z $2 ] ; then
	clear
	echo -e "\033[1;35mVector\033[0m"
	remake

	for EXEC in 'Compilation' 'Test'
	do
		vector$EXEC
	done

elif [[ $1 = 'stack' ]] && [ -z $2 ] ; then
	clear
	echo -e "\033[1;35mStack\033[0m"
	remake

	for EXEC in 'Compilation' 'Test'
	do
		stack$EXEC
	done

elif [[ $1 = 'map' ]] && [ -z $2 ] ; then
	clear
	echo -e "\033[1;35mMap\033[0m"
	remake

	for EXEC in 'Compilation' 'Test'
	do
		map$EXEC
	done

elif [[ $1 = 'set' ]] && [ -z $2 ] ; then
	clear
	echo -e "\033[1;35mSet\033[0m"
	remake

	for EXEC in 'Compilation' 'Test'
	do
		set$EXEC
	done

else
	printUsage

fi
