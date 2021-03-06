#pragma once
#include "verify_fall.h"
#include "falling_list.h"
#include "menu_commands.h"

#define DOWN            1
#define SLIDE_RIGHT     2
#define SLIDE_LEFT      3
#define KILL_ROCKFORD   4
int fall_object(MAP* map, t_list* falling_list, int* rockford_dead, ALLEGRO_SAMPLE *colision_sound);
void fall(MAP* map, t_knot* object,int drop_type, t_list* falling_list, int* rockford_dead, ALLEGRO_SAMPLE *colision_sound);
void kill_rockford(MAP* map, int* rockford_dead, ALLEGRO_SAMPLE *colision_sound);