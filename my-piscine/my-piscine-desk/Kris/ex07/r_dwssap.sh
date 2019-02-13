cat /etc/passwd | grep -v "^#" |
#!/bin/bash
I=2
MAX=$(cat /etc/passwd | ls -l | wc -l)
while [ $I -le $MAX ]; do
	if [ [ $I -ge $FT_LINE1 ] && [ $I -le $FT_LINE2 ]
	then
	cat /etc/passwd | ls -l | sed -n $I'p'
fi

	I=$(($I+2))
done

if [ $1 -gt 100 ]
then
echo Hey that\'s a large number.
pwd
fi
