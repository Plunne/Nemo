#include <stdio.h>
#include <stdlib.h>

typedef struct summable_s{
    int sum;
    int diff;
}summable_t;

void sum(summable_t** result, int* val)
{
    *result = (summable_t*) malloc((sizeof(val) / sizeof(int)) * sizeof(summable_t));
    (*result)->sum = val[0] + val[1];
    (*result)->diff = val[0] - val[1];
}

int main()
{
    summable_t* result;
    
    int val[]={8,4};
    
    sum(&result, val);
    
    printf("sum = %d\n", result->sum);
    printf("difference = %d\n", result->diff);
    free(result);
    
    return 0;
}