#!/bin/bash
declare -a dash
declare -a host_word
host_word=mayur
x=0
len=0

echo "i guess word"
for (( i=0 ; i < ${#host_word}; i++));
do
   dash[i]='_';
done
echo ${dash[*]}

while [ $x -lt 10 ]
    do
	echo -n "enter guess char: "
	read char_user
	for (( i=0; i < ${#host_word}; i++));
	    do
	    if [ $char_user = ${host_word:i:1} ]
	    then
		dash[$i]=$char_user
	    fi

#	tr -c "\n$char_user" " _" <<< "$host_word"
	    done

	    echo  ${dash[*]}

	    for (( i=0 ; i < ${#host_word}; i++ ));
		do
		    if [  ${host_word:i:1} = ${dash[i]} ]
		    then
			continue
		    else
			break
		    fi
		done

	    len=${#host_word}

	    if [ $i == $len ]
	    then
		echo "you won"
		exit
#	    else 
#		echo "you lose"
	    fi
	x=`expr $x + 1`
    done
	if [ $i == $len ]
	then
	    echo "you win"
	else
	    echo "you lose"
	fi
