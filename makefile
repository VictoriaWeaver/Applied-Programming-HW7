## for GCC
CC = gcc

##Compilcation Flags
CFLAGS= -Wall -ansi -pedantic

make: DetermineError GenData Correction



DetermineError: DetermineError.o
	$(CC) $(CFLAGS) -o DetermineError DetermineError.o

GenData: GenTestData.o
	$(CC) $(CFLAGS) -o GenData GenTestData.o

Correction: Correction.o
	$(CC) $(CFLAGS) -o Correction Correction.o

DetermineError.o: DetermineError.c
	$(CC) $(CFLAGS) -c DetermineError.c

GenTestData.o: GenTestData.c
	$(CC) $(CFLAGS) -c GenTestData.c

Correction.o: Correction.c
	$(CC) $(CFLAGS) -c Correction.c


######################### Block Used For Execution Of Programs #############
data:
	@echo "Analog Data Values: output to analog.txt"
	./GenData > analogValues.txt

output: 
	@echo "Uncorrected Digital Data Values: output to uncorrectedDigital.txt"
	./GenData | ./Device > uncorrectedDigital.txt

correction: 
	@echo "Corrected Digital Data Values: output to correctedDigital.txt"
	./GenData | ./Device | ./Correction > correctedDigital.txt

error:
	@echo "Error:"
	./GenData | ./Device | ./Correction | ./DetermineError

clean:
	rm -f *.o
	rm -f *.save
	rm -f *.gch
