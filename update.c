#include "update.h"

character* check_interact(world* inter_world, character* inter_character){
	//map interaction
	if (inter_character->current_room
		[inter_character->char_room_pos->x]
		[inter_character->char_room_pos->y] == 1 &&
		inter_character->char_room_pos->x == 0){
			//move up in world position, to bottom of next room
			inter_character->char_world_pos->x -= 1;
			inter_character->char_room_pos->x = 7;
			inter_character->char_room_pos->y = 4;
			change_current_room(inter_world, inter_character);
			
	}else if(inter_character->current_room
		[inter_character->char_room_pos->x]
		[inter_character->char_room_pos->y] == 1 &&
		inter_character->char_room_pos->x == 8){
			//move down in world pos, top of previous room
			inter_character->char_world_pos->x += 1;
			inter_character->char_room_pos->x = 1;
			inter_character->char_room_pos->y = 4;
			change_current_room(inter_world, inter_character);
			
	}
	
	
	//unit interaction

	return inter_character;
}

character* check_move(character* input_character, char input){
	switch(input){
		case 'w':
			if ( 
				input_character->current_room
					[input_character->char_room_pos->x - 1]
					[input_character->char_room_pos->y] != 0
				){
					input_character->char_room_pos->x -= 1;
				}
			break;
		case 'a':
			if ( 
				input_character->current_room
					[input_character->char_room_pos->x]
					[input_character->char_room_pos->y - 1] != 0
				){
					input_character->char_room_pos->y -= 1;
				}
			break;
		case 's':
			if ( 
				input_character->current_room
					[input_character->char_room_pos->x + 1]
					[input_character->char_room_pos->y] != 0
				){
					input_character->char_room_pos->x += 1;
				}
			break;
		case 'd':
			if ( 
				input_character->current_room
					[input_character->char_room_pos->x]
					[input_character->char_room_pos->y + 1] != 0
				){
					input_character->char_room_pos->y += 1;
				}
			break;
		case 'q':
			input_character->quit = 1;
			break;
	}
	
	return input_character;
}

character* update(world* update_world, character* update_character){
	printf("\n\nWhat do? ");
	char c = getchar();
	
	int i;
	for(i = 0; i < 24; i++)
		printf("\n");
	
	update_character = check_move(update_character, c);
	check_interact(update_world, update_character);
	

	
	return update_character;
}
