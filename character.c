
#include "character.h"

world_pos* new_world_pos() {
	world_pos *build_world_pos = malloc(sizeof(world_pos));
	
	build_world_pos->x = 8;
	build_world_pos->y = 4;
	
	return build_world_pos;
}

room_pos* new_room_pos() {
	room_pos *build_room_pos = malloc(sizeof(room_pos));
	
	build_room_pos->x = 4;
	build_room_pos->y = 4;
	
	return build_room_pos;
}

character* new_current_room(character* build_current_room){

	rooms *temp_rooms = new_rooms();
	
	int i = 0;
	for(i = 0; i < 9; i++)
		memcpy(build_current_room->current_room[i], temp_rooms->alpha[i], sizeof(temp_rooms->alpha[i]));
	
	free(temp_rooms);
	
	return build_current_room;
}

character* change_current_room(world* change_world, character* change_room){

	ushort room_ind = change_world->map
		[change_room->char_world_pos->x]
		[change_room->char_world_pos->y];
	
	int i = 0;
	
	switch(room_ind){
		case 1:
			for(i = 0; i < 9; i++)
				memcpy(change_room->current_room[i], change_world->room_map->alpha[i], sizeof(change_world->room_map->alpha[i]));
			break;
		case 2:
			for(i = 0; i < 9; i++)
				memcpy(change_room->current_room[i], change_world->room_map->pipe[i], sizeof(change_world->room_map->pipe[i]));
			break;
		case 9:
			for(i = 0; i < 9; i++)
				memcpy(change_room->current_room[i], change_world->room_map->omega[i], sizeof(change_world->room_map->omega[i]));
			break;
	}
	
	return change_room;
}

character* new_character(){
	character *build_character = malloc(sizeof(character));
	
	build_character->char_world_pos = new_world_pos();
	build_character->char_room_pos = new_room_pos();
	build_character = new_current_room(build_character);
	build_character->quit = 0;
	
	return build_character;
}

void destroy_character(character* dead_character){
	free(dead_character->char_world_pos);
	free(dead_character->char_room_pos);
	free(dead_character);
}
