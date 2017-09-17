FCFS:
	gcc FCFS.c -o FCFS.o
	./FCFS.o

SSTF:
	gcc SSTF.c -o SSTF.o
	./SSTF.o

Scan:
	gcc SCAN.c -o SCAN.o
	./SCAN.o

Look:
	gcc LOOK.c -o LOOK.o
	./LOOK.o

clean:
	rm *.o