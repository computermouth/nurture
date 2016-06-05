#include <stdlib.h>
#include <string.h>

typedef struct canvas {
	ushort grid[9][9];
} canvas;

canvas* new_canvas(){
	canvas *build_canvas = malloc(sizeof(canvas));
	
	ushort build_grid[9][9] = {
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
		{176, 176, 176, 176, 176, 176, 176, 176, 176},
	};
	
	int i = 0;
	for(i = 0; i < 9; i++)
		memcpy(build_canvas->grid[i], build_grid[i], sizeof(build_grid[i]));
		
	return build_canvas;
}

void destroy_canvas(canvas* dead_canvas){
	free(dead_canvas->grid);
}
