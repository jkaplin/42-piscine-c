#!/bin/bash
for i in `seq 0 23`;
do
	if [ $i -lt 10 ]
	then
		`mkdir ex0${i}`	
	else
		`mkdir ex${i}`	
	fi
done    
