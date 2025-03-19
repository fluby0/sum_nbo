sum_nbo : sum_nbo.o
	gcc -o sum_nbo sum_nbo.o

sum_nbo.o : sum_nbo.cpp
	gcc -c -o sum_nbo.o sum_nbo.cpp

clean :
	rm *.o sum_nbo
