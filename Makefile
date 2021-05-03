mystride : mystride.o mystride_test.o init.o
	gcc -o mystride mystride.o mystride_test.o init.o

mystride.o : mystride.c
	gcc -c -o mystride.o mystride.c

mystride_test.o : mystride_test.c
	gcc -c -o mystride_test.o mystride_test.c

init.o : init.c
	gcc -c -o init.o init.c

clean:
	rm *.o mystride