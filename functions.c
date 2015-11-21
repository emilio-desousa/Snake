#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

void setArray(int g[42][62])
{
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
                if ((i == 21) && (j > 25 && j < 36) )
                {
                    g[i][j] = 1; 
                } else 
                {
                  g[i][j] = 0;  
                }
            }
        }
    }
}