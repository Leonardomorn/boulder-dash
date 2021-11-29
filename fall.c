#include "fall.h"

void fall(MAP* map, t_knot* object,int drop_type, t_list* falling_list)
{
    if(drop_type == DOWN)
    {
        map->data[object->y][object->x] = MAP_HOLE;
        map->data[(object->y)+1][object->x] = object->entity;
        object->y++;
    }
    if(drop_type == SLIDE_RIGHT)
    {
        map->data[object->y][object->x] = MAP_HOLE;
        map->data[object->y][(object->x) +1] = object->entity;
        object->x++;    
    }
    if(drop_type == SLIDE_LEFT)
    {
        map->data[object->y][object->x] = MAP_HOLE;
        map->data[object->y][(object->x) -1] = object->entity;
        object->x--;    
    }
    if(drop_type == KILL_ROCKFORD)
    {
        if(map->data[((object->y)+1)][object->x] == MAP_ROCKFORD)
    {
        remove_list(falling_list, object);
        kill_rockford(map); 
        return;
    }
        else
        {
            map->data[object->y][object->x] = MAP_HOLE;
            map->data[(object->y)+1][object->x] = object->entity;
            object->y++;
        }
    }
}

void kill_rockford(MAP* map)
{
    int rockford_x;
    int rockford_y;
    find_rockford(&rockford_x, &rockford_y, *map );

    map->data[rockford_y -1 ][rockford_x -1] = MAP_EXPLOSION;
    map->data[rockford_y -1 ][rockford_x   ] = MAP_EXPLOSION;
    map->data[rockford_y -1 ][rockford_x +1] = MAP_EXPLOSION;
    map->data[rockford_y    ][rockford_x -1] = MAP_EXPLOSION;
    map->data[rockford_y    ][rockford_x   ] = MAP_EXPLOSION;
    map->data[rockford_y    ][rockford_x +1] = MAP_EXPLOSION;
    map->data[rockford_y +1 ][rockford_x -1] = MAP_EXPLOSION;
    map->data[rockford_y +1 ][rockford_x   ] = MAP_EXPLOSION;
    map->data[rockford_y +1 ][rockford_x +1] = MAP_EXPLOSION;

}

int fall_object(MAP* map, t_list* falling_list)
{
    int count;
    int drop;
    t_knot* knot_aux;

    if(list_is_empty(falling_list))
        return 0;
    knot_aux = falling_list->first;
    for (count = 0; count < falling_list->size; count++)
    {
        drop = object_can_fall(map, falling_list, knot_aux); /*return 0 case false, 
                                                               1 case drops down, 
                                                               2 case slide right ,
                                                               3 case slide left.
                                                               4 case kill rockford */
        if (drop)
        {
            fall(map, knot_aux, drop, falling_list);
        }
        else
        { 
            remove_list(falling_list, knot_aux);
        }
        knot_aux = knot_aux->next_knot;
    }
    return 1;
}

