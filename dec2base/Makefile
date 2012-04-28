CC = gcc
RM = rm
CFLAGS = -Wall -O2
PROG = dec2base
OBJS = main.o $(PROG).o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: main.c
	$(CC) -c $(CFLAGS) $<

$(PROG).o: $(PROG).c
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) -f $(PROG)

spotless: clean
	$(RM) -f $(OBJS)
