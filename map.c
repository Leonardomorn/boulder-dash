#include "map.h"

void fill_initial_map(MAP* map)
{
    fill_borders(map);
    fill_dirt(map);
    fill_wall(map);
    fill_exceptions(map);

}

void fill_wall(MAP* map)
{
    //int* map_int[][] = (int *) map;
    int i;
    int j;
    i = 7;
    for (j =1 ; j<=30 ; j++ )
    {
        map->data[i][j] = MAP_WALL;
    }
    i = 14;
    for (j = 9 ; j <= 38 ; j++)
    {
        map->data[i][j] = MAP_WALL; 
    }
}
void fill_borders(MAP* map)
{
    int i;
    int j;

    for (i = 0; i<22; i++)
        {
            for(j = 0; j< 40 ; j++)
            {
                if (i == 0 || i == 21 || j == 0 || j == 39)   // boarder places
                {
                    map->data[i][j] = MAP_STEEL;                
                }
                
            }
        }    

}

void fill_dirt(MAP* map)
{
    int i;
    int j;

    for (i = 1; i<21; i++)
        {
            for(j = 1; j< 39 ; j++)
            {
                map->data[i][j] = MAP_DIRT;
            }
        }    

}

void fill_exceptions(MAP* map) /*ordenado por linha*/
{
    map->data[1][7] = MAP_HOLE; map->data[1][10] = MAP_DIAMOND; map->data[1][12] = MAP_BOULDER; map->data[1][13] = MAP_HOLE; map->data[1][19] = MAP_BOULDER; map->data[1][21] = MAP_BOULDER; map->data[1][29] = MAP_HOLE; map->data[1][34] = MAP_BOULDER; 
    map->data[2][2] = MAP_BOULDER; map->data[2][3] = MAP_ROCKFORD; map->data[2][4] = MAP_BOULDER; map->data[2][11] = MAP_HOLE; map->data[2][21] = MAP_BOULDER; map->data[2][22] = MAP_DIAMOND; map->data[2][25] = MAP_BOULDER; map->data[2][30] = MAP_HOLE; map->data[2][36] = MAP_HOLE;
    map->data[3][11] = MAP_HOLE; map->data[3][14] = MAP_HOLE; map->data[3][20] = MAP_BOULDER; map->data[3][25] = MAP_BOULDER; map->data[3][34] = MAP_BOULDER;
    map->data[4][1] = MAP_BOULDER; map->data[4][3] = MAP_HOLE;  map->data[4][4] = MAP_HOLE; map->data[4][14] = MAP_BOULDER; map->data[4][21] = MAP_BOULDER; map->data[4][24] = MAP_BOULDER; map->data[4][29] = MAP_BOULDER; map->data[4][33] = MAP_BOULDER; 
    map->data[5][1] = MAP_BOULDER; map->data[5][3] = MAP_HOLE; map->data[5][4] = MAP_BOULDER; map->data[5][14] = MAP_BOULDER; map->data[5][15] = MAP_BOULDER; map->data[5][18] = MAP_BOULDER; map->data[5][27] = MAP_BOULDER; map->data[5][34] = MAP_BOULDER; map->data[5][36] = MAP_BOULDER; map->data[5][37] = MAP_HOLE;
    map->data[6][4] = MAP_BOULDER; map->data[6][7] = MAP_BOULDER; map->data[6][16] = MAP_BOULDER; map->data[6][22] = MAP_BOULDER; map->data[6][24] = MAP_HOLE; map->data[6][25] = MAP_BOULDER; map->data[6][34] = MAP_BOULDER; map->data[6][36] = MAP_BOULDER; map->data[6][37] = MAP_BOULDER;
    map->data[7][34] = MAP_BOULDER; map->data[7][37] = MAP_BOULDER;
    map->data[8][2] = MAP_HOLE; map->data[8][6] = MAP_BOULDER; map->data[8][9] = MAP_DIAMOND; map->data[8][11] = MAP_HOLE; map->data[8][14] = MAP_BOULDER; map->data[8][16] = MAP_BOULDER; map->data[8][27] = MAP_DIAMOND; map->data[8][29] = MAP_BOULDER; map->data[8][30] = MAP_HOLE; map->data[8][37] = MAP_BOULDER;
    map->data[9][3] = MAP_DIAMOND; map->data[9][9] = MAP_BOULDER; map->data[9][15] = MAP_HOLE; map->data[9][24] = MAP_BOULDER; map->data[9][25] = MAP_HOLE; map->data[9][26] = MAP_HOLE; map->data[9][27] = MAP_BOULDER; map->data[9][30] = MAP_DIAMOND; map->data[9][35] = MAP_BOULDER;
    map->data[10][4] = MAP_BOULDER; map->data[10][7] = MAP_BOULDER; map->data[10][9] = MAP_BOULDER; map->data[10][24] = MAP_BOULDER; map->data[10][25] = MAP_BOULDER; map->data[10][27] = MAP_BOULDER; map->data[10][30] = MAP_BOULDER;
    map->data[11][2] = MAP_HOLE; map->data[11][8] = MAP_BOULDER;  map->data[11][17] = MAP_BOULDER; map->data[11][18] = MAP_BOULDER; map->data[11][19] = MAP_HOLE; map->data[11][27] = MAP_BOULDER; map->data[11][30] = MAP_BOULDER; map->data[11][32] = MAP_DIAMOND; map->data[11][37] = MAP_HOLE;
    map->data[12][2] = MAP_BOULDER; map->data[12][5] = MAP_HOLE;  map->data[12][8] = MAP_BOULDER; map->data[12][10] = MAP_HOLE; map->data[12][11] = MAP_HOLE; map->data[12][17] = MAP_BOULDER; map->data[12][19] = MAP_BOULDER; map->data[12][20] = MAP_DIAMOND; map->data[12][23] = MAP_DIAMOND; map->data[12][28] = MAP_BOULDER; map->data[12][32] = MAP_BOULDER; map->data[12][35] = MAP_DIAMOND; map->data[12][37] = MAP_BOULDER;
    map->data[13][2] = MAP_DIAMOND; map->data[13][3] = MAP_BOULDER; map->data[13][18] = MAP_BOULDER; map->data[13][19] = MAP_BOULDER; map->data[13][20] = MAP_BOULDER; map->data[13][23] = MAP_BOULDER; map->data[13][32] = MAP_DIAMOND; map->data[13][38] = MAP_BOULDER;
    map->data[15][1] = MAP_HOLE; map->data[15][2] = MAP_HOLE; map->data[15][12] = MAP_HOLE; map->data[15][16] = MAP_DIAMOND; map->data[15][21] = MAP_BOULDER;map->data[15][27] = MAP_BOULDER; map->data[15][31] = MAP_BOULDER;
    map->data[16][1] = MAP_BOULDER; map->data[16][2] = MAP_HOLE; map->data[16][12] = MAP_BOULDER; map->data[16][13] = MAP_BOULDER; map->data[16][16] = MAP_BOULDER; map->data[16][25] = MAP_BOULDER; map->data[16][32] = MAP_BOULDER; map->data[16][34] = MAP_BOULDER; map->data[16][35] = MAP_HOLE; map->data[16][38] = MAP_STEEL; // 16 38 is exit
    map->data[17][2] = MAP_BOULDER; map->data[17][5] = MAP_BOULDER; map->data[17][14] = MAP_BOULDER; map->data[17][20] = MAP_BOULDER; map->data[17][22] = MAP_HOLE; map->data[17][23] = MAP_HOLE;  map->data[17][28] = MAP_DIAMOND; map->data[17][32] = MAP_BOULDER; map->data[17][34] = MAP_BOULDER; map->data[17][35] = MAP_BOULDER;
    map->data[18][5] = MAP_BOULDER; map->data[18][6] = MAP_DIAMOND; map->data[18][9] = MAP_HOLE; map->data[18][18] = MAP_BOULDER; map->data[18][25] = MAP_BOULDER; map->data[18][27] = MAP_BOULDER; map->data[18][28] = MAP_DIAMOND; map->data[18][35] = MAP_BOULDER; 
    map->data[19][4] = MAP_HOLE; map->data[19][7] = MAP_HOLE; map->data[19][9] = MAP_BOULDER; map->data[19][12] = MAP_BOULDER; map->data[19][14] = MAP_BOULDER; map->data[19][15] = MAP_BOULDER; map->data[19][25] = MAP_BOULDER; map->data[19][27] = MAP_BOULDER; map->data[19][28] = MAP_DIAMOND; map->data[19][35] = MAP_BOULDER; map->data[19][38] = MAP_BOULDER;
    map->data[20][2] = MAP_DIAMOND; map->data[20][7] = MAP_BOULDER; map->data[20][13] = MAP_HOLE; map->data[20][23] = MAP_HOLE; map->data[20][25] = MAP_BOULDER; map->data[20][28] = MAP_BOULDER; map->data[20][33] = MAP_BOULDER; map->data[20][37] = MAP_BOULDER;
}

int load_sprites()
{
    DIR *folder;

    folder = opendir("resources/images");
    if(folder == NULL)
    {
        puts("Unable to read directory");
        return(1);
    }
    else
    {
        puts("Directory is opened!");
    }




    closedir(folder);

    return(0);
}

int draw_map(MAP map, ALLEGRO_BITMAP* boulder, ALLEGRO_BITMAP* diamond, ALLEGRO_BITMAP* dirt, ALLEGRO_BITMAP* exit, ALLEGRO_BITMAP* magicwall, ALLEGRO_BITMAP* steel, ALLEGRO_BITMAP* wall, ALLEGRO_BITMAP* rockford, ALLEGRO_BITMAP* hole, ALLEGRO_BITMAP* explosion)
{
    int i;
    int j;

    for (i = 0; i<22; i++)
        {
            for(j = 0; j< 40 ; j++)
            {
                switch (map.data[i][j])
                {
                case MAP_BOULDER:
                    al_draw_bitmap(boulder, j*16, (i+1)*16, 0);
                    break;
                case MAP_DIAMOND:
                    al_draw_bitmap(diamond, j*16, (i+1)*16, 0);
                    break;
                case MAP_DIRT:
                    al_draw_bitmap(dirt, j*16, (i+1)*16, 0);
                    break;
                case MAP_EXIT:
                    al_draw_bitmap(exit, j*16, (i+1)*16, 0);
                    break;
                case MAP_MAGICWALL:
                    al_draw_bitmap(magicwall, j*16, (i+1)*16, 0);
                    break;
                case MAP_STEEL:
                    al_draw_bitmap(steel, j*16, (i+1)*16, 0);
                    break;
                case MAP_WALL:
                    al_draw_bitmap(wall, j*16, (i+1)*16, 0);
                    break;
                case MAP_ROCKFORD:
                    al_draw_bitmap(rockford, j*16, (i+1)*16, 0);
                    break;      
                case MAP_HOLE:
                    al_draw_bitmap(hole, j*16, (i+1)*16, 0);
                    break;
                case MAP_EXPLOSION:
                    al_draw_bitmap(explosion, j*16, (i+1)*16, 0);
                    break;         
                default:
                    break;
                }   
            }
        }   
    return 0; 
}

int find_rockford(int*x, int *y, MAP map)
{   
    int i;
    int j;
    int has_rockford = 0;
    for (i = 0; i<22; i++)
    {
        for(j = 0; j< 40 ; j++)
        {
            if (map.data[i][j] == MAP_ROCKFORD)
            {
                *y = i;
                *x = j;
                has_rockford = 1;
                return has_rockford;
            }

        }
    }    
    return has_rockford;
}
void open_exit(MAP* map)
{
    map->data[16][38] = MAP_EXIT;
}