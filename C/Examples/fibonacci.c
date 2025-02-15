#include <stdio.h>
#include <stdlib.h>

int* gen_fibo(int n) {

    int *fibo = (int *) malloc(n * sizeof(int));

    if (fibo == NULL)
    {
        exit(EXIT_FAILURE);
    }

    *fibo = 0;
    *(fibo + 1) = 1;

    for (int i=2; i < n; i++)
    {
        *(fibo + i) = *(fibo + (i - 1)) + *(fibo + (i - 2));
    }

    return fibo;
}

int main(void)
{
    int *fibonacci = gen_fibo(6);

    free(fibonacci);

    return 0;
}