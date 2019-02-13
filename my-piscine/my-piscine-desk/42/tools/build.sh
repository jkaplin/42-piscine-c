#!/bin/sh


		echo building work/ex00/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex00/ft_create_elem.c work/ex00/main.c -o work/ex00/main
	
		cd work/ex00; make; cd ../..;
	
		echo building work/ex01/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex01/ft_list_push_back.c work/ex01/main.c -o work/ex01/main
	
		cd work/ex01; make; cd ../..;
	
		echo building work/ex02/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex02/ft_list_push_front.c work/ex02/main.c -o work/ex02/main
	
		cd work/ex02; make; cd ../..;
	
		echo building work/ex03/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex03/ft_list_size.c work/ex03/main.c -o work/ex03/main
	
		cd work/ex03; make; cd ../..;
	
		echo building work/ex04/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex04/ft_list_last.c work/ex04/main.c -o work/ex04/main
	
		cd work/ex04; make; cd ../..;
	
		echo building work/ex05/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex05/ft_list_push_params.c work/ex05/main.c -o work/ex05/main
	
		cd work/ex05; make; cd ../..;
	
		echo building work/ex06/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex06/ft_list_clear.c work/ex06/main.c -o work/ex06/main
	
		cd work/ex06; make; cd ../..;
	
		echo building work/ex07/main
		gcc -Wall -Wextra -Werror stupidity.c work/ex07/ft_list_at.c work/ex07/main.c -o work/ex07/main
	
		cd work/ex07; make; cd ../..;
	