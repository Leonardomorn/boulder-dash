#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <internal_math.h>
#define boulder   1
#define diamond   2
#define dirt      3
#define exit      4
#define magicwall 5
#define steel     6
#define wall      7
typedef struct MAP  {
    int entity;
    MAP 2D_map[][];
} MAP;  
