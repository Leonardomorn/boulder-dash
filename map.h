#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <dirent.h>

#define MAP_BOULDER 1
#define MAP_DIAMOND 2
#define MAP_DIRT 3
#define MAP_EXIT 4
#define MAP_MAGICWALL 5
#define MAP_STEEL 6
#define MAP_WALL 7
#define MAP_ROCKFORD 8
#define MAP_HOLE 9
#define MAP_EXPLOSION 10

#define HORIZONTAL_PIXEL 1300
#define VERTICAL_PIXEL 700
#define HORIZONTAL_TILE (HORIZONTAL_PIXEL/16 + 1) 
#define VERTICAL_TILE (VERTICAL_PIXEL/16 + 1)


typedef struct {
    int data[VERTICAL_TILE][HORIZONTAL_TILE];
    int width;
    int height;
}MAP;

void fill_initial_map(MAP* map);
void fill_wall(MAP* map);
void fill_borders(MAP* map);
void fill_dirt(MAP* map);
void fill_exceptions(MAP* map); //ordenado por linha
int draw_map(MAP map, ALLEGRO_BITMAP* boulder, ALLEGRO_BITMAP* diamond, ALLEGRO_BITMAP* dirt, ALLEGRO_BITMAP* exit,
     ALLEGRO_BITMAP* magicwall, ALLEGRO_BITMAP* steel, ALLEGRO_BITMAP* wall, ALLEGRO_BITMAP* rockford, ALLEGRO_BITMAP* hole, ALLEGRO_BITMAP* explosion);
int find_rockford(int*x, int *y, MAP map);
void open_exit(MAP* map);
