

#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>

#include "character.h"

character* check_interact(world*, character*);

character* check_move(character*, char);

character* update(world*, character*);

#endif
