#include "../../includes/cub3D.h"

void ft_print_arr(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        if(i >= 10)
            printf(" %d  %s\n", i, arr[i]);
        else
            printf(" %d   %s\n", i, arr[i]);
        i++;
    }
}