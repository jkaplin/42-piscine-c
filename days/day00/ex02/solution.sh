mkdir test0
touch -t 201806012047 test0
chmod ugo=x test0
chmod uo+r test0
chmod u+w test0
echo "123" >> test1
touch -t 201806012146 test1
chmod u=rwx test1
chmod g=x test1
chmod o=r test1
mkdir test2
touch -t 201806012245 test2
chmod uo=r test2
chmod u+x test2
touch -t 201806012344 test3
chmod uo=r test3
chmod go+x test3
echo "1" >> test4
touch -t 201806012343 test4
chmod ug=r test4
chmod u+w test4
chmod o=x test4
touch -t 201806012344 test5
chmod ug=r test5
ln -s test0 test6
touch -h -t 201806012220 test6
