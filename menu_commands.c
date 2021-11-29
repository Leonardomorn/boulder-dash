#include "menu_commands.h"

void restart_game(MAP* map, t_list* falling_list)
{
    destroy_list(falling_list);
    fill_initial_map(map);
    initialize_list(falling_list);
}