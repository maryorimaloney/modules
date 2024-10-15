#!/bin/bash

# check for an argument
if [ -z "$1" ]; then
		echo "Usage statement: ./valgrind.sh (file name)"
		exit 1
fi

# SOURCES: https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks

echo "Running Valgrind on $1"
echo "_________________________________________"
#valgrind --leak-check=full --error-exitcode=1 $1 2> ./tmp
#running valgring and saving output
valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind_output.txt $1 > /dev/null

#checking if output exist
if [ -s valgrind_output.txt ]; then
		
		# number of total errors
		grep "ERROR SUMMARY: 0 errors from 0 contexts" valgrind_output.txt > /dev/null
		ERR1=$?
		if [ $ERR1 -eq 1 ] ; then 
				echo "Errors Present!"
		else
				echo "No Errors Present"
		fi

		# number of leaks
		grep "in use at exit: 0 bytes in 0 blocks" valgrind_output.txt > /dev/null
		ERR2=$?
		if [ $ERR2 -eq 1 ] ; then 
				echo "Leaks Present!"
		else
				echo "No Leaks Present"
		fi
else
		echo "_________________________________________"
		echo "File not found/ empty!!!"
		exit 1
fi
rm valgrind_output.txt

exit
