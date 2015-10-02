CC = gcc -O3

all : destiny_tiger

destiny_tiger: destiny.o tiger.o sboxes.o
	$(CC) -o destiny_tiger destiny.o tiger.o sboxes.o

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f destiny_tiger destiny.o tiger.o sboxes.o