FCFS:
	gcc FCFS.c -o FCFS.o
	./FCFS.o

SSTF:
	gcc SSTF.c -o SSTF.o
	./SSTF.o

Scan:
	gcc SCAN.c -o SCAN.o
	./SCAN.o

clean:
	rm *.o