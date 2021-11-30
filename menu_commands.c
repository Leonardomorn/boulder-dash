#include "menu_commands.h"

void restart_game(MAP* map, t_list* falling_list, int* diamond_counter, int* rockford_dead)
{
    destroy_list(falling_list);
    fill_initial_map(map);
    initialize_list(falling_list);
    *diamond_counter = 0;
    *rockford_dead = 0;
}