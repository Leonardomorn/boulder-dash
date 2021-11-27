#pragma once
#include "verify_fall.h"
#include "falling_list.h"

#define DOWN        1
#define SLIDE_RIGHT 2
#define SLIDE_LEFT  3

int fall_object(MAP* map, t_list* falling_list);
void fall(MAP* map, t_knot* object,int drop_type);