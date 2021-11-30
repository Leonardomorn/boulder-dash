#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "map.h"
#include "falling_list.h"
#include "movement.h"
#include "fall.h"
#include "menu_commands.h"



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
    int diamond_counter = 0; 
    int diamonds_needed = 10;
    int clock =150;
    int exit_closed = 1;
    int rockford_dead = 0;
    int is_on_menu = 0;

    fill_initial_map(&map);
    initialize_list(&falling_objects);

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "acodec");


    ALLEGRO_SAMPLE *falling_sound = al_load_sample("resources/sounds/fall.wav");
    ALLEGRO_SAMPLE *creak_sound = al_load_sample("resources/sounds/creak.wav");
    ALLEGRO_SAMPLE *colision_sound = al_load_sample("resources/sounds/colision.wav");
    ALLEGRO_SAMPLE *victory_sound = al_load_sample("resources/sounds/victory.wav");
    ALLEGRO_SAMPLE *diamond_sound = al_load_sample("resources/sounds/diamond.wav");

    must_init(diamond_sound, "diamond_sound");
    must_init(creak_sound, "creak_sound");
    must_init(colision_sound, "colision_sound");
    must_init(victory_sound, "victory_sound");
    must_init(falling_sound, "falling_sound");


    al_reserve_samples(5);

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
    must_init(timer, "timer");
    
    ALLEGRO_TIMER *timer_fall = al_create_timer(1.0 / 5.0);
    must_init(timer_fall, "timer_fall");

    ALLEGRO_TIMER *timer_clock = al_create_timer(1.0 / 1.0);
    must_init(timer_clock, "timer_clock");

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
    ALLEGRO_BITMAP *explosion = al_load_bitmap("resources/images/explosion.png");
    must_init(explosion, "explosion");    

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_timer_event_source(timer_fall));
    al_register_event_source(queue, al_get_timer_event_source(timer_clock));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    al_start_timer(timer_fall);
    al_start_timer(timer_clock);
    while (1)
    {
        al_wait_for_event(queue, &event);
        

        
        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            /*game logic goes here*/
        if(event.timer.source == timer_fall){
            if(fall_object(&map, &falling_objects, &rockford_dead, colision_sound))
            {
                al_play_sample(falling_sound, 1,0,1, ALLEGRO_PLAYMODE_ONCE, 0);
            }
        }
        if(event.timer.source == timer_clock){
        clock --;
        }
        if (diamond_counter == diamonds_needed && exit_closed)
        {
            open_exit(&map);
            al_play_sample(creak_sound, 1,0,1, ALLEGRO_PLAYMODE_ONCE, 0);

            exit_closed = 0;

        }

            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                move_up(&map, &falling_objects, &diamond_counter, diamond_sound);
            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                move_down(&map, &falling_objects, &diamond_counter, diamond_sound);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                move_left(&map, &falling_objects, &diamond_counter, diamond_sound);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                move_right(&map, &falling_objects, &diamond_counter, diamond_sound);
            if (event.keyboard.keycode == ALLEGRO_KEY_R)
                restart_game(&map, &falling_objects, &diamond_counter, &rockford_dead);
            if (event.keyboard.keycode == ALLEGRO_KEY_H)
                is_on_menu = 1;

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
            draw_map(map, boulder, diamond, dirt, exit, magicwall, steel, wall, rockford, hole, explosion);
            al_draw_textf(font, al_map_rgb(255,255,255), 0, 0, 0, "DIAMOND: %d", diamond_counter);
            al_draw_textf(font, al_map_rgb(255,255,255), 100, 0, 0, "DIAMONDS NEEDED: %d", diamonds_needed);
            al_draw_textf(font, al_map_rgb(255,255,255), 300, 0, 0, "Score: %d", diamond_counter *10);
            al_draw_textf(font, al_map_rgb(255,255,255), 400, 0, 0, "Time: %d", clock);
            al_flip_display();


            redraw = false;
        }
        if (event.timer.source == timer_fall && rockford_dead){
            sleep(1);
            restart_game(&map, &falling_objects, &diamond_counter, &rockford_dead);
        }
        if (is_on_menu)
          {
            if (redraw && al_is_event_queue_empty(queue))
            {
                al_clear_to_color(al_map_rgb(71, 47, 23));
            }
            switch (event.type)
            {

            case ALLEGRO_EVENT_KEY_DOWN:
                if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                    move_up(&map, &falling_objects, &diamond_counter, diamond_sound);
                if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                    move_down(&map, &falling_objects, &diamond_counter, diamond_sound);
                if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                    move_left(&map, &falling_objects, &diamond_counter, diamond_sound);
                if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                    move_right(&map, &falling_objects, &diamond_counter, diamond_sound);
                if (event.keyboard.keycode == ALLEGRO_KEY_R)
                    restart_game(&map, &falling_objects, &diamond_counter, &rockford_dead);
                if (event.keyboard.keycode == ALLEGRO_KEY_H)
                    is_on_menu = 1;

                if (event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            }

          }
        }
    }



    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_timer(timer_fall);
    al_destroy_timer(timer_clock);
    al_destroy_sample(falling_sound);
    al_destroy_sample(diamond_sound);
    al_destroy_sample(victory_sound);
    al_destroy_sample(creak_sound);
    al_destroy_sample(colision_sound);


    al_destroy_event_queue(queue);
    return 0;
}