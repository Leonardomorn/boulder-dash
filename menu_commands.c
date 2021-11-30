#include "menu_commands.h"

void restart_game(MAP* map, t_list* falling_list, int* diamond_counter, int* rockford_dead, int* exit_closed)
{
    destroy_list(falling_list);
    fill_initial_map(map);
    initialize_list(falling_list);
    *diamond_counter = 0;
    *rockford_dead = 0;
    *exit_closed = 1;
}
void end_game(ALLEGRO_SAMPLE* victory_sound, int* clock, int* diamond_score, int rank_array[]  )
{
    int allscore = *clock + *diamond_score;
    al_play_sample(victory_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

    
        		for(int i = 0; i < 10; i++)
    		{
    			if(rank_array[i] < allscore)
    			{
    				rank_array[9] = 0;
    				for(int l = 9; l > i; l--)
    				{
    					rank_array[l] = rank_array[l-1];
    				}
    				rank_array[i] = allscore;
    				break;
    			}
    		}

}