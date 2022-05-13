#!/bin/bash

input="./values.txt"
output="./output.txt"
executable="../convert"

if [ -e "$output" ]
		then
	`rm $output`
fi

while read -r line
	do

	if [[ $line == \#* ]] ;
	then
		echo "" >>$output
		echo "" >>$output
		echo "$line" >> $output
	else
		echo "./convert $line" >> $output
	fi

	if [[ $line != \#* ]] ;
	then
		$executable $line >> $output
	fi

	echo "" >>$output

done < "$input"