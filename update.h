
#include <stdio.h>

#include "character.h"

character* update(world* update_world, character* update_character){
	printf("\n\nWhat do? ");
	char c = getchar();
	
	int i;
	for(i = 0; i < 24; i++)
		printf("\n");
	
	switch(c){
		case 'w':
			if ( 
				update_character->current_room
					[update_character->char_room_pos->x - 1]
					[update_character->char_room_pos->y] != 0
				){
					update_character->char_room_pos->x -= 1;
				}
			break;
		case 'a':
			if ( 
				update_character->current_room
					[update_character->char_room_pos->x]
					[update_character->char_room_pos->y - 1] != 0
				){
					update_character->char_room_pos->y -= 1;
				}
			break;
		case 's':
			if ( 
				update_character->current_room
					[update_character->char_room_pos->x + 1]
					[update_character->char_room_pos->y] != 0
				){
					update_character->char_room_pos->x += 1;
				}
			break;
		case 'd':
			if ( 
				update_character->current_room
					[update_character->char_room_pos->x]
					[update_character->char_room_pos->y + 1] != 0
				){
					update_character->char_room_pos->y += 1;
				}
			break;
		case 'q':
			update_character->quit = 1;
			break;
	}
	
	return update_character;
}
