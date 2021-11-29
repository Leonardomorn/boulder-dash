#include "verify_fall.h"

void start_fall_object(MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    verify_fall_upper(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_upper_right(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_right(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_down_right(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_down(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_down_left(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_left(map,previous_rockford_x,previous_rockford_y,falling_boulder);
    verify_fall_upper_left(map,previous_rockford_x,previous_rockford_y,falling_boulder);
}

void verify_fall_upper(MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y -1][previous_rockford_x] == MAP_BOULDER) || 
            (map->data[previous_rockford_y -1][previous_rockford_x] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y][previous_rockford_x]) == MAP_HOLE)
        {

            append(falling_boulder, 
                previous_rockford_x,
                previous_rockford_y -1, 
                map->data[previous_rockford_y-1][previous_rockford_x]);
        }
    }
    return;
}

void verify_fall_upper_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y -1][previous_rockford_x +1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y -1][previous_rockford_x +1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y][previous_rockford_x +1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x +1, 
                previous_rockford_y -1, 
                map->data[previous_rockford_y-1][previous_rockford_x+1]);
            return;
        }
        else if ((map->data[previous_rockford_y][previous_rockford_x +1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y][previous_rockford_x +1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y -1][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x +1, 
                    previous_rockford_y -1,
                    map->data[previous_rockford_y-1][previous_rockford_x+1]);
                return;
            }
        }
    }
    return;
}

void verify_fall_upper_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y -1][previous_rockford_x -1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y -1][previous_rockford_x -1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y][previous_rockford_x -1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x-1, 
                previous_rockford_y-1, 
                map->data[previous_rockford_y-1][previous_rockford_x-1]);
            return;
        }
        else if ((map->data[previous_rockford_y][previous_rockford_x -1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y][previous_rockford_x -1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y -1][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x -1, 
                    previous_rockford_y -1,
                    map->data[previous_rockford_y-1][previous_rockford_x-1]);
                return;
            }
        }
    }
    return;
}

void verify_fall_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y][previous_rockford_x +1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y][previous_rockford_x +1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y +1][previous_rockford_x +1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x+1, 
                previous_rockford_y, 
                map->data[previous_rockford_y][previous_rockford_x+1]);
            return;
        }
        else if ((map->data[previous_rockford_y+1][previous_rockford_x +1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y+1][previous_rockford_x +1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y +1][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x +1, 
                    previous_rockford_y,
                    map->data[previous_rockford_y][previous_rockford_x+1]);
                return;
            }
        }
    }
    return;
}

void verify_fall_down_right (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y +1][previous_rockford_x +1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y +1][previous_rockford_x +1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y +2][previous_rockford_x +1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x +1,
                previous_rockford_y +1,
                map->data[previous_rockford_y+1][previous_rockford_x+1]);
            return;
        }
        else if ((map->data[previous_rockford_y +2][previous_rockford_x +1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y +2][previous_rockford_x +1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y +1][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y +2][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x +1, 
                    previous_rockford_y +1,
                    map->data[previous_rockford_y+1][previous_rockford_x+1]);
                return;
            }
        }
    }
    return;
}

void verify_fall_down (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    return;
}

void verify_fall_down_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
        if((map->data[previous_rockford_y +1][previous_rockford_x -1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y +1][previous_rockford_x -1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y +2][previous_rockford_x -1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x -1,
                previous_rockford_y +1,
                map->data[previous_rockford_y+1][previous_rockford_x-1]);
            return;
        }
        else if ((map->data[previous_rockford_y +2][previous_rockford_x -1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y +2][previous_rockford_x -1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y +1][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y +2][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x -1, 
                    previous_rockford_y +1,
                    map->data[previous_rockford_y+1][previous_rockford_x-1]);
                return;
            }
        }
    }
    return;
}

void verify_fall_left (MAP* map, int previous_rockford_x, int previous_rockford_y, t_list* falling_boulder)
{
    if((map->data[previous_rockford_y][previous_rockford_x -1] == MAP_BOULDER) || 
            (map->data[previous_rockford_y][previous_rockford_x -1] == MAP_DIAMOND) )
    {
        if((map->data[previous_rockford_y +1][previous_rockford_x -1]) == MAP_HOLE)
        {

            append(falling_boulder,
                previous_rockford_x -1, 
                previous_rockford_y, 
                map->data[previous_rockford_y][previous_rockford_x -1]);
            return;
        }
        else if ((map->data[previous_rockford_y+1][previous_rockford_x -1] == MAP_BOULDER) ||
                    (map->data[previous_rockford_y+1][previous_rockford_x -1] == MAP_DIAMOND))
        {
            if((map->data[previous_rockford_y][previous_rockford_x] == MAP_HOLE) && 
                (map->data[previous_rockford_y +1][previous_rockford_x] == MAP_HOLE))
            {
                append(falling_boulder,
                    previous_rockford_x -1, 
                    previous_rockford_y,
                    map->data[previous_rockford_y][previous_rockford_x+1]);
                return;
            }
        }
    }
    return;
}

int object_can_fall(MAP* map, t_list* falling_list, t_knot* object)
/*return 0 case false, 1 case drops down, 2 case slide right , 3 case slide left, 4 case kill rockford */
{
    if((map->data[((object->y)+1)][object->x]) == MAP_HOLE)
    {
        return 1;
    }
    if((map->data[(object->y)+1][object->x] == MAP_BOULDER) ||
        (map->data[(object->y)+1][object->x] == MAP_DIAMOND))
    { 
        if((map->data[object->y][(object->x)+1]) == MAP_HOLE)
        {
            if((map->data[(object->y)+1][(object->x)+1]) == MAP_HOLE)
            {
                return 2;
            }
        }
        if((map->data[object->y][(object->x)-1]) == MAP_HOLE)
        {
            if((map->data[(object->y)+1][(object->x)-1]) == MAP_HOLE)
            {
                return 3;
            }
        }
    }
    else if((map->data[((object->y)+1)][object->x]) == MAP_ROCKFORD)
    {
        return 4;
    }
    return 0;
}