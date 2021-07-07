CC := gcc
LD := gcc

CFLAGS := -c
LDFLAGS := -lc

all: History

install: History

clean:
	del *.o

History: History.o \
		  Tokenizer.o \
         Tester.o
	$(LD) $(LDFLAGS) $^ -o $@

Tester.o:tester.c
	$(CC) $(CFLAGS) -o $@ $<
History.o:history.c
	$(CC) $(CFLAGS) -o $@ $<
Tokenizer.o:tokenizer.c
	$(CC) $(CFLAGS) -o $@ $<
