CC = gcc
CFLAGS = -Wall -g

tempfilter: tempfilter.o list.o listelmt.o listdata.o
	${CC} ${CFLAGS} tempfilter.o list.o listelmt.o listdata.o -o tempfilter
tempfilter.o: tempfilter.c list.h
	${CC} ${CFLAGS} -c tempfilter.c
list.o: list.c list.h listelmt.h listdata.h
	${CC} ${CFLAGS} -c list.c
listelmt.o: listelmt.c listelmt.h listdata.h
	${CC} ${CFLAGS} -c listelmt.c
listdata.o: listdata.c listdata.h
	${CC} ${CFLAGS} -c listdata.c

clean:
	/bin/rm tempfilter.o list.o listelmt.o listdata.o
