#!/bin/bash
ODD=1
MAX=$(ls -l | wc -l)
while [ $ODD -le $MAX ]; do
	ls -l | sed -n $ODD'p'
	ODD=$(($ODD+2))
done
