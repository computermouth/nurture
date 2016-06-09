OBJS = main.c tiles.c world.c update.c draw.c character.c

OBJ_NAME = nurture

.PHONY: clean all

all: $(OBJS)
	gcc $(OBJS) -Wall -o $(OBJ_NAME)

clean:
	rm *.o nurture
