#include <stdio.h>
#include <stdlib.h>

int* alloc_2D(int lignes, int colonnes, int val) {

    int* p_grid = (int*) malloc((lignes * colonnes) * sizeof(int));

    if(p_grid == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < lignes; i++)
    {
        for (int j=0; j < colonnes; j++)
        {
            *(p_grid + ((i * colonnes) + j)) = val * (i + 1);
        }
    }

    return p_grid;
}

int main(void)
{
    int *dynarray_2D = alloc_2D(2, 3, 99);

    free(dynarray_2D);

    return 0;
}