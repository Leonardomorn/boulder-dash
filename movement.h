#pragma once
#include "map.h"
#include "verify_fall.h"

void move_up   (MAP* map, t_list* falling_boulder, int* diamond_counter, ALLEGRO_SAMPLE *diamond_sound, int* victory);
void move_down (MAP* map, t_list* falling_boulder, int* diamond_counter, ALLEGRO_SAMPLE *diamond_sound, int* victory);
void move_left (MAP* map, t_list* falling_boulder, int* diamond_counter, ALLEGRO_SAMPLE *diamond_sound, int* victory);
void move_right(MAP* map, t_list* falling_boulder, int* diamond_counter, ALLEGRO_SAMPLE *diamond_sound, int* victory);