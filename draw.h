
#include <stdio.h>

#include "world.h"
#include "character.h"



void draw(world* draw_world, character* draw_character){
	
	char buffer[10][10];
	
	int i;
	for(i = 0; i < 10; i++)
		buffer[i][10] = 0;
	
	ushort room_ind = draw_world->map
		[draw_character->char_world_pos->x]
		[draw_character->char_world_pos->y];
	
	//printf("%d", room_ind);
	
	//~ int i, j;
	//~ for(i = 0; i < 10; i++){
		//~ for(j = 0; j < 10; j++){
			//~ switch(draw_world->[i][j])
		//~ }
	//~ }
	
}
