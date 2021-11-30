#include "map.h"
#include "falling_list.h"

void restart_game(MAP* map, t_list* falling_list, int* diamond_counter, int* rockford_dead, int* exit_closed);
void end_game(ALLEGRO_SAMPLE* victory_sound, int* clock, int* score, int rank_array[] );