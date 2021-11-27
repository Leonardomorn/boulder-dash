#pragma once
#include <stdio.h>
#include <dirent.h>
#include "map.h"
#include "falling_list.h"

void start_fall_object(MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_upper(MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_upper_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_upper_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_down_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_down (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_down_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
void verify_fall_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder);
int object_can_fall(MAP* map, t_list* falling_list, t_knot* object);