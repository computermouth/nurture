OBJS = main.c tiles.c world.c update.c draw.c character.c

OBJ_NAME = nurture

.PHONY: all clean lint

all: $(OBJS)
	gcc $(OBJS) -Wall -o $(OBJ_NAME)

clean:
	rm *.o nurture

lint:
	cppcheck --language=c --enable=warning,style --template=gcc *.c *.h
