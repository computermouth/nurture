OBJS = main.c

OBJ_NAME = main

all: $(OBJS)
	gcc $(OBJS) -Wall -o $(OBJ_NAME)
