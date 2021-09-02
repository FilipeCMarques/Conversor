#include "countingSort.h"
#include <stdio.h>

void countingSort(int *v, size_t tam, size_t interval)
{
    int *count = calloc((int)interval + 1, sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        count[v[i]]++;
    }

    for(int i = 0, j = 0; i < interval+1; i++){
        if (count[i] > 0){
            while(count[i]-- != 0){
                v[j++] = i;
            }
        }
    }
    free(count);
}