
#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <string.h>

#include "world.h"

typedef struct world_pos {
	ushort x;
	ushort y;
} world_pos;

typedef struct room_pos {
	ushort x;
	ushort y;
} room_pos;

typedef struct character {
	world_pos* char_world_pos;
	room_pos*  char_room_pos;
	ushort current_room[9][9];
	ushort quit;
} character;

world_pos* new_world_pos();

room_pos* new_room_pos();

character* new_current_room(character*);

character* change_current_room(world*, character*);

character* new_character();

void destroy_character(character*);

#endif
