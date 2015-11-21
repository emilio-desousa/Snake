#include <stdio.h>
#include <stdlib.h>

void setArray(int g[42][62]){
    int i, j;
    for (i = 0; i < 42; ++i)
    {
        for (j = 0; j < 62; ++j)
        {
            if ( (i == 0) || (i == 41) || (j == 0) || (j == 61) )
            {
                g[i][j] = 2;
            } else 
            {
                g[i][j] = 0;
            }
            //printf("g[%d][%d] => %d\n", i, j, g[i][j]);
        }
    }
}

int main(void)
{
    int i, j;
    int grille[42][62];
    setArray(grille);
    for (i = 0; i < 42; ++i)
    {
        for (j = 0; j < 62; ++j)
        {
            //arr[i][j] = i+j;
            printf("grille[%d][%d] => %d\n", i, j, grille[i][j]);
        }
    }
}