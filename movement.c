#include "movement.h"

void move_up(MAP* map, t_list* falling_boulder)
{
    int rockford_x;
    int rockford_y;
    int has_moved =0;

    find_rockford(&rockford_x,&rockford_y,*map);

    if (map->data[rockford_y - 1][rockford_x] == MAP_DIRT || 
        map->data[rockford_y - 1][rockford_x] == MAP_EXIT ||
        map->data[rockford_y - 1][rockford_x] == MAP_HOLE ||  
        map->data[rockford_y - 1][rockford_x] == MAP_DIAMOND )
    {
       map->data[rockford_y][rockford_x] = MAP_HOLE;
       map->data[rockford_y - 1][rockford_x] = MAP_ROCKFORD;
       has_moved = 1;
    }
    if(has_moved){
        start_fall_object(map, rockford_x, rockford_y, falling_boulder);
    }  
}


void move_down(MAP* map, t_list* falling_boulder)
{
    int rockford_x;
    int rockford_y;
    int has_moved = 0;

    find_rockford(&rockford_x,&rockford_y,*map);

    if (map->data[rockford_y + 1][rockford_x] == MAP_DIRT || 
        map->data[rockford_y + 1][rockford_x] == MAP_EXIT ||
        map->data[rockford_y + 1][rockford_x] == MAP_HOLE ||  
        map->data[rockford_y + 1][rockford_x] == MAP_DIAMOND )
    {
       map->data[rockford_y][rockford_x] = MAP_HOLE;
       map->data[rockford_y + 1][rockford_x] = MAP_ROCKFORD;
       has_moved = 1;
    }

    if (has_moved)
    {
        start_fall_object(map, rockford_x, rockford_y, falling_boulder);
    }

}
void move_left(MAP* map, t_list* falling_boulder)
{
    int rockford_x;
    int rockford_y;
    int has_moved = 0;
    int pushed_boulder = 0;
    find_rockford(&rockford_x,&rockford_y,*map);

    if (map->data[rockford_y][rockford_x -1] == MAP_DIRT || 
        map->data[rockford_y][rockford_x -1] == MAP_EXIT ||
        map->data[rockford_y][rockford_x -1] == MAP_HOLE ||  
        map->data[rockford_y][rockford_x -1] == MAP_DIAMOND )
    {
       map->data[rockford_y][rockford_x] = MAP_HOLE;
       map->data[rockford_y][rockford_x -1] = MAP_ROCKFORD;
       has_moved = 1;
    }
    else if((map->data[rockford_y][rockford_x -1] == MAP_BOULDER) && (map->data[rockford_y][rockford_x -2] == MAP_HOLE) )
    {
        map->data[rockford_y][rockford_x] = MAP_HOLE;
        map->data[rockford_y][rockford_x -1] = MAP_ROCKFORD;
        map->data[rockford_y][rockford_x -2] = MAP_BOULDER;
        has_moved = 1;
        pushed_boulder = 1;
    }
    if(has_moved)
    {
        start_fall_object(map, rockford_x, rockford_y, falling_boulder);
    }
    if(pushed_boulder)
    {
        verify_fall_left(map, rockford_x -1 , rockford_y, falling_boulder);
    }
}
void move_right(MAP* map, t_list* falling_boulder)
{
    int rockford_x;
    int rockford_y;
    int has_moved = 0;
    int pushed_boulder = 0;
    find_rockford(&rockford_x,&rockford_y,*map);

    if (map->data[rockford_y][rockford_x +1] == MAP_DIRT || 
        map->data[rockford_y][rockford_x +1] == MAP_EXIT ||
        map->data[rockford_y][rockford_x +1] == MAP_HOLE ||  
        map->data[rockford_y][rockford_x +1] == MAP_DIAMOND )
    {
       map->data[rockford_y][rockford_x] = MAP_HOLE;
       map->data[rockford_y][rockford_x +1] = MAP_ROCKFORD;
       has_moved = 1;
    }
    else if((map->data[rockford_y][rockford_x +1] == MAP_BOULDER) && (map->data[rockford_y][rockford_x +2] == MAP_HOLE) )
    {
        map->data[rockford_y][rockford_x] = MAP_HOLE;
        map->data[rockford_y][rockford_x +1] = MAP_ROCKFORD;
        map->data[rockford_y][rockford_x +2] = MAP_BOULDER;
        has_moved = 1;
        pushed_boulder = 1;
    }

    if(has_moved)
    {
        start_fall_object(map, rockford_x, rockford_y, falling_boulder);
    }
    if(pushed_boulder)
    {
        verify_fall_right(map, rockford_x + 1, rockford_y, falling_boulder);
    }
}