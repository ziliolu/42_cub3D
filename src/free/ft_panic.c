#include "../../includes/cub3D.h"

int ft_panic(t_root *root)
{
    free(root->tinfo->north);
    free(root->tinfo->south);
    free(root->tinfo->west);
    free(root->tinfo->east);

    free(root->tinfo);
    free(root);
    return (1);
}