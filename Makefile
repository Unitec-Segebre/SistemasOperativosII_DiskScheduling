FCFS:
	gcc FCFS.c -o FCFS.o
	./FCFS.o

SSTF:
	gcc SSTF.c -o SSTF.o
	./SSTF.o

Scan:
	gcc SCAN.c -o SCAN.o
	./SCAN.o

C-Scan:
	gcc C-SCAN.c -o C-SCAN.o
	./C-SCAN.o

Look:
	gcc LOOK.c -o LOOK.o
	./LOOK.o

C-Look:
	gcc C-LOOK.c -o C-LOOK.o
	./C-LOOK.o

clean:
	rm *.o