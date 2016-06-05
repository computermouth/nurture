
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "world.h"
#include "character.h"
#include "draw.h"


int main(){
	world *n_world = new_world();
	character *n_character = new_character();
	
	
	draw(n_world, n_character);
	
	destroy_world(n_world);
	destroy_character(n_character);
	
	return 0;
}
