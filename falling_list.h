#pragma once
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct t_knot
{
    int x,y, entity;
    struct t_knot *next_knot;
    struct t_knot *prev_knot;
}t_knot;

typedef struct t_list
{
    struct t_knot* first;
    struct t_knot* last;

    int size;
}t_list;

int initialize_list( t_list *l);
int list_is_empty (t_list *l);
int add_in_empty_list (t_list *l, t_knot *knot);
int add_end_list(t_list *l, t_knot *new_knot);
int append(t_list *l,int x_cord,int y_cord, int entity);
void remove_first_list(t_list *l);
void destroy_list(t_list *l);
int remove_between_knot(t_list *l, t_knot* knot);
int remove_final_knot(t_list *l, t_knot* knot);
int already_on_list(t_list *l,int x_cord,int y_cord);
