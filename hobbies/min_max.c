#include <stdio.h>

#define LENGTH 30

void min_max(int *arr, int len, int *min, int *max)
{
    size_t ctr=0;
    *max = *min = arr[ctr];

    while( ctr < len )
    {
        if ( arr[ctr] > *max )
            *max = arr[ctr];
        else if ( arr[ctr] < *min )
            *min = arr[ctr];
        ctr++;
    }

}

int main(void)
{
    int min = -1, max = -1;
    int array[LENGTH];

    for(size_t c=0;c<LENGTH/2; c++) {
        array[c] = c+3;
        printf("%d ", array[c]);
    }

    for(size_t c=LENGTH/2;c<LENGTH; c++) {
        array[c] = c-3;
        printf("%d ", array[c]);
    }

    putchar('\n');

    min_max(array, LENGTH, &min, &max);

    printf("Min=%d , Max=%d\n", min,max);

    return 0;
}
