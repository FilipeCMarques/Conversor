#include "insertionSort.h"
#include "../utils.h"

void insertionSort(int *v, size_t size){
    int i, j, chave;

    for(i = 1; i < size; i++){
        chave = v[i];
        for (j = i-1; j >= 0 && v[j] > chave; j--){
            v[j+1] = v[j];
        }
        v[j+1] = chave;
    }
}
