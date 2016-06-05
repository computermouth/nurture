
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "world.h"
#include "character.h"
#include "draw.h"
#include "update.h"

int main(){
	world *n_world = new_world();
	character *n_character = new_character();

	while (n_character->quit == 0){
		draw(n_world, n_character);
		n_character = update(n_world, n_character);
	}
	
	destroy_world(n_world);
	destroy_character(n_character);
	
	return 0;
}
