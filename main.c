#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "map.h"
#include "falling_list.h"
#include "movement.h"
#include "fall.h"

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{
    MAP map;
    t_list falling_objects;

    fill_initial_map(&map);
    initialize_list(&falling_objects);

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");
    
    ALLEGRO_TIMER *timer_fall = al_create_timer(1.0 / 5.0);
    must_init(timer_fall, "timer_fall");


    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY *disp = al_create_display(HORIZONTAL_PIXEL, VERTICAL_PIXEL);
    must_init(disp, "display");

    ALLEGRO_FONT *font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    ALLEGRO_BITMAP *boulder = al_load_bitmap("resources/images/boulder.png");
    must_init(boulder, "boulder");
    ALLEGRO_BITMAP *diamond = al_load_bitmap("resources/images/diamond.png");
    must_init(diamond, "diamond");
    ALLEGRO_BITMAP *dirt = al_load_bitmap("resources/images/dirt.png");
    must_init(dirt, "dirt");
    ALLEGRO_BITMAP *exit = al_load_bitmap("resources/images/exit.png");
    must_init(exit, "exit");
    ALLEGRO_BITMAP *magicwall = al_load_bitmap("resources/images/magicwall.png");
    must_init(magicwall, "magicwall");
    ALLEGRO_BITMAP *steel = al_load_bitmap("resources/images/steel.png");
    must_init(steel, "steel");
    ALLEGRO_BITMAP *wall = al_load_bitmap("resources/images/wall.png");
    must_init(wall, "wall");
    ALLEGRO_BITMAP *rockford = al_load_bitmap("resources/images/rockford.png");
    must_init(rockford, "rockford");
    ALLEGRO_BITMAP *hole = al_load_bitmap("resources/images/hole.png");
    must_init(hole, "hole");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            /*game logic goes here*/
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                move_up(&map, &falling_objects);
            else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                move_down(&map, &falling_objects);
            else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                move_left(&map, &falling_objects);
            else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                move_right(&map, &falling_objects);

            if (event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(71, 47, 23));
            // draw_score();
            draw_map(map, boulder, diamond, dirt, exit, magicwall, steel, wall, rockford, hole);

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}