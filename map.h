#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "internal_math.h"

#define map_boulder 1
#define map_diamond 2
#define map_dirt 3
#define map_exit 4
#define map_magicwall 5
#define map_steel 6
#define map_wall 7
#define map_rockford 8
#define map_hole 9

#define HORIZONTAL_PIXEL 1300
#define VERTICAL_PIXEL 700
#define HORIZONTAL_TILE (HORIZONTAL_PIXEL/16 + 1)
#define VERTICAL_TILE (VERTICAL_PIXEL/16 + 1)

void allocate_map(int **map[]);
void free_map(int **map[]);
int draw_initial_map(int** map[]);
