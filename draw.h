
#include <stdio.h>

#include "world.h"
#include "character.h"



void draw(world* draw_world, character* draw_character){
	
	char buffer[10][10];
	memset(buffer, 0, sizeof(buffer[0][0]) * 10 * 10);
	
	ushort room_ind = draw_world->map
		[draw_character->char_world_pos->x]
		[draw_character->char_world_pos->y];
	
	
	int i, j;
	
	switch(room_ind){
		case 0:
			break;
		case 1:
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					if(draw_world->room_map->alpha[i][j] == 0){
						buffer[i][j] = 'X';
					} else {
						buffer[i][j] = ' ';
					}					
				}
			}
			break;
		case 2:
			break;
		case 9:
			break;
	}
	
	buffer[draw_character->char_room_pos->x][draw_character->char_room_pos->y] = 'A';
	
	for(i = 0; i < 10; i++)
		printf("%s\n", buffer[i]);
}
