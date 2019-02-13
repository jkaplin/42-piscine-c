ldapsearch | grep cn:  | rev | cut -d  -f1 | rev | grep bon | wc -l | bc
