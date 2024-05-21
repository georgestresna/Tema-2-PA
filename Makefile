build:
	gcc main.c grafuri.c liste.c -o clasament
run:
	./clasament ./Input/test1.in ./OutputGraf/test1.out ./OutputScor/test1.out
clean:
	rm clasament
