
#include "draw.h"

void draw(world* draw_world, character* draw_character){
	
	char buffer[10][10];
	memset(buffer, 0, sizeof(buffer[0][0]) * 10 * 10);
	
	ushort room_ind = draw_world->map
		[draw_character->char_world_pos->x]
		[draw_character->char_world_pos->y];
		
	printf("\nX: %d\tY: %d\n", draw_character->char_world_pos->x, draw_character->char_world_pos->y);
	printf("\nX: %d\tY: %d\n", draw_character->char_room_pos->x, draw_character->char_room_pos->y);
	
	
	int i, j;
	
	switch(room_ind){
		case 0:
			break;
		case 1:
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					buffer[i][j] = tile_fetch(draw_world->room_map->alpha[i][j]);				
				}
			}
			break;
		case 2:
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					buffer[i][j] = tile_fetch(draw_world->room_map->pipe[i][j]);				
				}
			}
			break;
		case 9:
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					buffer[i][j] = tile_fetch(draw_world->room_map->omega[i][j]);				
				}
			}
			break;
	}
	
	buffer[draw_character->char_room_pos->x][draw_character->char_room_pos->y] = 'A';
	
	for(i = 0; i < 10; i++)
		printf("%s\n", buffer[i]);
}
