CC=g++ -std=c++11
exe_file=prog

$(exe_file): prog.cpp menu.o pizza.o restaurant.o
	$(CC) prog.cpp menu.o pizza.o restaurant.o -o $(exe_file) 

menu.o: menu.cpp pizza.h menu.h emp_hours.h restaurant.h
	$(CC) -c menu.cpp

pizza.o: pizza.cpp pizza.h emp_hours.h
	$(CC) -c pizza.cpp

restaurant.o: restaurant.cpp menu.h restaurant.h emp_hours.h
	$(CC) -c restaurant.cpp

clean: 
	rm -f *.o $(exe_file)