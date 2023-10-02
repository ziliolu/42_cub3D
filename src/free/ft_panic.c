#include "../../includes/cub3D.h"

int ft_panic(t_root *root)
{
    // free(root->tinfo->north.addr);
    // free(root->tinfo->south.addr);
    // free(root->tinfo->west.addr);
    // free(root->tinfo->east.addr);

    // free(root->tinfo);
    free(root);
    return (1);
}