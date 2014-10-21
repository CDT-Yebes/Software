#
CC	= gcc
CFLAGS	= -O
#
#	Where to put the binary
#
BIN	= /usr/local/bin
#
MAINV	= 1.1
SUBV	= 13
VERSION	= $(MAINV).$(SUBV)
FILES	= README Makefile tclCheck.c COPYRIGHT tclCheck.1
#
all	: tclCheck

tclCheck : tclCheck.o
	$(CC) -s -o tclCheck tclCheck.o $(LIBS)
	
install	: tclCheck
	cp tclCheck $(BIN)

clean	:
	rm -f tclCheck tclCheck.o
