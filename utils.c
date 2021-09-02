#include "utils.h"

void printArray(int *v, size_t size){
    printf("[");
    for(int i = 0; i < size; ++i){
        if (i == size-1)
            printf("%d", v[i]);
        else
            printf("%d, ", v[i]);
    }
        
    printf("]\n");
}

void generate(int *v, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        v[i] = rand() % (int)size;
    }
}

//gerando vetor crescente
void generateCrescente(int *v, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        v[i] = i;
    }
}
//gerando vetor decrescente
void generateDecrescente(int *v, size_t size)
{
    for (int i = 0, j = size; i < size; ++i, --j)
    {
        v[i] = j;
    }
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
