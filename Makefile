mystride : mystride.o mystride_test.o init.o functions.o
	gcc -o mystride mystride.o mystride_test.o init.o functions.o

mystride.o : mystride.c
	gcc -c -o mystride.o mystride.c

mystride_test.o : mystride_test.c
	gcc -c -o mystride_test.o mystride_test.c

init.o : init.c
	gcc -c -o init.o init.c

functions.o : functions.c
	gcc -c -o functions.o functions.c

clean:
	rm *.o mystride