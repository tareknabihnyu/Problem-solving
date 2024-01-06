OBJS	= contactbst.o main.o
SOURCE	= contactbst.cpp main.cpp
HEADER	= contactbst.h contact.h myvector.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

contactbst.o: contactbst.cpp
	$(CC) $(FLAGS) contactbst.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)