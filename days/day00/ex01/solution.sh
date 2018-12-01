echo "888888881088888888208888888830888888884" >> testDay00 #creates a file called testDay00 and inserts a 40 byte string to that file (40 characters including the '\0' = 40 bytes) as requested 40 in ls -l.
touch -t 201806012342 testDay00
chmod ugo=r testDay00
chmod go+x testDay00
