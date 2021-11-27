#include "falling_list.h"

int initialize_list(t_list *l)
/*initialize a list, return 1 in success and 0 in failure*/
{
    l->first = NULL;
    l->last  = NULL;
    l->size  =    0;
    if(list_is_empty(l))
        return 1;
    return 0;
}

int list_is_empty (t_list *l)
/*Verify if list is empty, return 1 in success and 0 in failure */
{
    if (l->first == NULL && l->size == 0)
        return 1;
    return 0;
}

int add_in_empty_list (t_list *l, t_knot *knot)
/*returns 1 in success and 0 in failure*/
{
    l->first = knot;
    l->last  = knot;
    knot->prev_knot = NULL;
    knot->next_knot = NULL;
    l->size++;
    if(l->first == NULL)
    {
        return 0;
    }
    return 1;
}


int add_end_list(t_list *l, t_knot *new_knot)
/*adds a knot in the end of the list, return 1 in sucess and 0 in failure*/
{
    new_knot->next_knot = NULL;
    new_knot->prev_knot = l->last;
    l->last->next_knot = new_knot;
    l->last = new_knot;
    l->size++;    
    if (new_knot->next_knot == NULL)
        return 1;
    return 0;
}

int append(t_list *l,int x_cord,int y_cord, int entity)
/*return 1 in success and 0 on failure*/
{
    t_knot* new_knot;
    new_knot = malloc(sizeof(t_knot));
    new_knot->x = x_cord;
    new_knot->y = y_cord;
    new_knot->entity = entity;

    if(list_is_empty(l))
    {
        add_in_empty_list(l, new_knot);
        return 1;
    }
    else if(already_on_list(l, x_cord, y_cord)) 
    {
        return 0;
    }
    else
    {
        add_end_list(l, new_knot);
        return 1;
    }
    return 0;
}

void remove_first_list(t_list *l)
/*remove list's first element*/
{
    t_knot *knot_aux;    
    knot_aux = l->first;
    if (list_is_empty(l))                  /*case list is empty*/
    {
        printf ("\n empty list, removing is impossible\n");
        return;
    }
    if (l->first->next_knot == NULL)   /*case there is only one knot*/
    {
        free(knot_aux);
        l->first = NULL;
        l->size--;
        return;
    }

    l->first = knot_aux->next_knot;
    knot_aux->next_knot->prev_knot = NULL;
    free(knot_aux);
    l->size--;
    return;
}

void destroy_list(t_list *l)
/*remove all elements on list*/
{
    if (list_is_empty(l))                  /*case list is empty*/
    {
        printf ("\n impossible destroy, list is empty\n");
        return;
    }
    while(!list_is_empty(l))               /*remove until list is empty*/
    {
        remove_first_list(l);
    }    
    return;
}

int remove_between_knot(t_list *l, t_knot* knot)
{
    if (l->size < 3)
    {
        printf("can't remove a between knot");
        return 0;
    }
    

    knot->next_knot->prev_knot = knot->prev_knot;
    knot->prev_knot->next_knot = knot->next_knot;
    free(knot);
    l->size--;
    return 1;
}

int remove_final_knot(t_list *l, t_knot* knot)
{
    if (l->size <2)
    {
        printf("can't remove last knot");
        return 0;
    }

    knot->prev_knot->next_knot = NULL;
    l->last = knot->prev_knot;
    free(knot);
    l->size--;
    return 1;
}

int already_on_list(t_list *l,int x_cord,int y_cord)
{
    t_knot* knot_aux;
    int count;
    knot_aux = l->first;

    for (count = 0; count < l->size; count++)
    {
        if((knot_aux->x == x_cord) && (knot_aux->y == y_cord))
        {
            return 1;
        }
        knot_aux = knot_aux->next_knot;
    }
    return 0;
    
}

