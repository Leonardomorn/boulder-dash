#include "fall.h"

void fall(MAP* map, t_knot* object,int drop_type)
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
                                                               3 case slide left */
        if (drop)
        {
            fall(map, knot_aux, drop);
        }
        // else
        // { 
        //     unapend (falling_list, knot_aux);
        // }
        knot_aux = knot_aux->next_knot;
    }
    return 1;
}

