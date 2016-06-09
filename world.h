
#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <string.h>

typedef struct rooms {
	// i
	ushort omega[9][9];
	// ||
	ushort pipe[9][9];
	// !
	ushort alpha[9][9];
} rooms;

typedef struct world {
	ushort map[9][9];
	rooms* room_map;
} world;

rooms* new_rooms();

world* new_world();

void destroy_world(world*);

#endif
