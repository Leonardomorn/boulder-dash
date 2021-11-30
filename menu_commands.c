#include "menu_commands.h"

void restart_game(MAP* map, t_list* falling_list, int* diamond_counter, int* rockford_dead, int* exit_closed, int* clock, int* royale)
{
    destroy_list(falling_list);
    fill_initial_map(map);
    initialize_list(falling_list);
    *diamond_counter = 0;
    *rockford_dead = 0;
    *exit_closed = 1;
	*clock = 150;
	*royale = 0;
}
void end_game(ALLEGRO_SAMPLE* victory_sound, int clock, int diamond_score, long rank_array[]  )
{
    long allscore = clock + diamond_score;
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

int just_started_royale(MAP* map)
{
	if (map->data[0][0] == MAP_EXPLOSION)
		return 0;
	return 1;
	
}



void reduce_map_royale(MAP* map, int* rockford_dead)
{
	int i,rockford_x, rockford_y;
	int counter = 0;

	find_rockford(&rockford_x,&rockford_y, *map);
	for(i=0; i< 22; i++)
	{
		if(map->data[i][0] == MAP_EXPLOSION)
			counter++;	
	}

		if(map->data[21][0] != MAP_EXPLOSION)
		{
			for(i = 0; i <= counter ; i++)
			{
				if(map->data[counter-i][i] == MAP_ROCKFORD)
				{
					*rockford_dead = 1;	
				}
				else
					map->data[counter-i][i] = MAP_EXPLOSION;
				return;
			}
		}

}
void battle_royale(MAP* map, ALLEGRO_SAMPLE * explosion_sound, int* rockford_dead, int* royale)
{
	if(just_started_royale(map))
	{
		map->data[0][0] = MAP_EXPLOSION;
		al_play_sample(explosion_sound, 0.1, 0 , 1, ALLEGRO_PLAYMODE_ONCE, 0);
	}
	else
	{
		reduce_map_royale(map, rockford_dead);

		al_play_sample(explosion_sound, 0.1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0  );

		if(map->data[21][0] == MAP_EXPLOSION)
		{
			*royale = 0;
		}
	}
}