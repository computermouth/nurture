

#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>

#include "character.h"

character* check_interact(world* inter_world, character* inter_character);

character* check_move(character* input_character, char input);

character* update(world* update_world, character* update_character);

#endif
