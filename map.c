#include <stdio.h>
#include <dirent.h>
#include "map.h"

void allocate_map(int** map[])
{
    int i;

    for (i = 0; i < VERTICAL_TILE; i++)
    {
        map[i] = (int*)malloc(HORIZONTAL_TILE * sizeof(int));
    }

}

int fill_initial_map(int** map[])
{
    fill_borders(&map);
    fill_dirt(&map);
    fill_wall(&map);
    fill_exceptions(&map);

}

int fill_wall(int** map[])
{
    int i;
    int j;
    i = 7;
    for (j =1 ; j<=30 ; j++ )
    {
        map[i][j] = map_wall;
    }
    i = 14;
    for (j = 9 ; j <= 38 ; j++)
    {
        map[i][j] = map_wall; 
    }
}
int fill_borders(int** map[])
{
    int i;
    int j;

    for (i = 0; i<22; i++)
        {
            for(j = 0; j< 40 ; j++)
            {
                if (i == 0 || i == 21 || j == 0 || j == 39)   // boarder places
                {
                    map[i][j] = map_steel;                
                }
                
            }
        }    
    return 0;    
}

int fill_dirt(int** map[])
{
    int i;
    int j;

    for (i = 1; i<21; i++)
        {
            for(j = 1; j< 39 ; j++)
            {
                map[i][j] = map_dirt;
            }
        }    
    return 0;
}

int fill_exceptions(int** map[]) //ordenado por linha
{
    map[1][7] = map_hole; map[1][10] = map_diamond; map[1][12] = map_boulder; map[1][13] = map_hole; map[1][19] = map_boulder; map[1][21] = map_boulder; map[1][29] = map_hole; map[1][34] = map_boulder; 
    map[2][2] = map_boulder; map[2][3] = map_rockford; map[2][4] = map_boulder; map[2][11] = map_hole; map[2][21] = map_boulder; map[2][22] = map_diamond; map[2][25] = map_boulder; map[2][30] = map_hole; map[2][36] = map_hole;
    map[3][11] = map_hole; map[3][14] = map_hole; map[3][20] = map_boulder; map[3][22] = map_boulder; map[3][25] = map_boulder; map[3][34] = map_boulder;
    map[4][1] = map_boulder; map[4][3] = map_hole;  map[4][4] = map_hole; map[4][14] = map_boulder; map[4][21] = map_boulder; map[4][24] = map_boulder; map[4][29] = map_boulder; map[4][33] = map_boulder; 
    map[5][1] = map_boulder; map[5][3] = map_hole; map[5][4] = map_boulder; map[5][14] = map_boulder; map[5][15] = map_boulder; map[5][18] = map_boulder; map[5][27] = map_boulder; map[5][34] = map_boulder; map[5][36] = map_boulder; map[5][37] = map_hole;
    map[6][4] = map_boulder; map[6][7] = map_boulder; map[6][16] = map_boulder; map[6][22] = map_boulder; map[6][24] = map_hole; map[6][25] = map_boulder; map[6][34] = map_boulder; map[6][36] = map_boulder; map[6][37] = map_boulder;
    map[7][34] = map_boulder; map[7][37] = map_boulder;
    map[8][2] = map_hole; map[8][6] = map_boulder; map[8][9] = map_diamond; map[8][11] = map_hole; map[8][14] = map_boulder; map[8][16] = map_boulder; map[8][27] = map_diamond; map[8][29] = map_boulder; map[8][30] = map_hole; map[8][37] = map_boulder;
    map[9][3] = map_diamond; map[9][9] = map_boulder; map[9][15] = map_hole; map[9][24] = map_boulder; map[9][25] = map_hole; map[9][26] = map_hole; map[9][27] = map_boulder; map[9][30] = map_diamond; map[9][35] = map_boulder;
    map[10][4] = map_boulder; map[10][7] = map_boulder; map[10][9] = map_boulder; map[10][24] = map_boulder; map[10][25] = map_boulder; map[10][27] = map_boulder; map[10][30] = map_boulder;
    map[11][2] = map_hole; map[11][8] = map_boulder;  map[11][17] = map_boulder; map[11][18] = map_boulder; map[11][19] = map_hole; map[11][27] = map_boulder; map[11][30] = map_boulder; map[11][32] = map_diamond; map[11][37] = map_hole;
    map[12][2] = map_boulder; map[12][5] = map_hole;  map[12][8] = map_boulder; map[12][10] = map_hole; map[12][11] = map_hole; map[12][17] = map_boulder; map[12][19] = map_boulder; map[12][20] = map_diamond; map[12][23] = map_diamond; map[12][28] = map_boulder; map[12][32] = map_boulder; map[12][35] = map_diamond; map[12][37] = map_boulder;
    map[13][2] = map_diamond; map[13][3] = map_boulder; map[13][18] = map_boulder; map[13][19] = map_boulder; map[13][20] = map_boulder; map[13][23] = map_boulder; map[13][32] = map_diamond; map[13][38] = map_boulder;
    map[15][1] = map_hole; map[15][2] = map_hole; map[15][12] = map_hole; map[15][16] = map_diamond; map[15][21] = map_boulder;map[15][27] = map_boulder; map[15][31] = map_boulder;
    map[16][1] = map_boulder; map[16][2] = map_hole; map[16][12] = map_boulder; map[16][13] = map_boulder; map[16][16] = map_boulder; map[16][25] = map_boulder; map[16][32] = map_boulder; map[16][34] = map_boulder; map[16][35] = map_hole; map[16][38] = map_exit;
    map[17][2] = map_boulder; map[17][5] = map_boulder; map[17][14] = map_boulder; map[17][20] = map_boulder; map[17][22] = map_hole; map[17][23] = map_hole;  map[17][28] = map_diamond; map[17][32] = map_boulder; map[17][34] = map_boulder; map[17][35] = map_boulder;
    map[18][5] = map_boulder; map[18][6] = map_diamond; map[18][9] = map_hole; map[18][18] = map_boulder; map[18][25] = map_boulder; map[18][27] = map_boulder; map[18][28] = map_diamond; map[18][35] = map_boulder; 
    map[19][4] = map_hole; map[19][7] = map_hole; map[19][9] = map_boulder; map[19][12] = map_boulder; map[19][14] = map_boulder; map[19][15] = map_boulder; map[19][25] = map_boulder; map[19][27] = map_boulder; map[19][28] = map_diamond; map[19][35] = map_boulder; map[19][38] = map_boulder;
    map[20][2] = map_diamond; map[20][7] = map_boulder; map[20][13] = map_hole; map[20][23] = map_hole; map[20][25] = map_boulder; map[20][28] = map_boulder; map[20][33] = map_boulder; map[20][37] = map_boulder;
}

int draw_bitmap_from_images_directory()
{
    DIR *folder;

    folder = opendir("Images");
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

