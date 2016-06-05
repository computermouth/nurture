#include <stdlib.h>
#include <string.h>

#ifndef WORLD_H
#define WORLD_H

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

rooms* new_rooms(){
	rooms *build_rooms = malloc(sizeof(rooms));
	
	// 1 -- door
	// 2 -- empty
	
	ushort build_omega[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
	};
	
	ushort build_pipe[9][9] = {
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
	};
	
	ushort build_alpha[9][9] = {
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	
	int i = 0;
	for(i = 0; i < 9; i++){
		memcpy(build_rooms->omega[i], build_omega[i], sizeof(build_omega[i]));
		memcpy(build_rooms->pipe[i], build_pipe[i], sizeof(build_pipe[i]));
		memcpy(build_rooms->alpha[i], build_alpha[i], sizeof(build_alpha[i]));
	
	}
		
	return build_rooms;
}

world* new_world(){
	world *build_world = malloc(sizeof(world));
	
	// 1 -- alpha
	// 2 -- pipe
	// 9 -- omega
	
	ushort build_map[9][9] = {
		{0, 0, 0, 0, 9, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
	};
	
	int i = 0;
	for(i = 0; i < 9; i++)
		memcpy(build_world->map[i], build_map[i], sizeof(build_map[i]));
		
	build_world->room_map = new_rooms();
	
	return build_world;
}

void destroy_world(world* dead_world){
	free(dead_world->room_map);
	free(dead_world);
}

#endif
