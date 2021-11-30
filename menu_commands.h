#include "map.h"
#include "falling_list.h"

void restart_game(MAP* map, t_list* falling_list, int* diamond_counter, int* rockford_dead, int* exit_closed, int* clock, int* royale);
void end_game(ALLEGRO_SAMPLE* victory_sound, int* clock, int* score, int rank_array[] );
void battle_royale(MAP* map, ALLEGRO_SAMPLE * explosion_sound, int* rockford_dead, int* royale);
void reduce_map_royale(MAP* map, int* rockford_dead);
int explosion_counter(MAP* map);