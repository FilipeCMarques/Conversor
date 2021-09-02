#include "mergeSort.h"
#include "../Utils/utils.h"

void merge(int *v, int l, int mid, size_t size)
{
    /*Iteradores, respectivamente, da primeira metade, segunda e
    do vetor ordenado
    */
    int i, j, k;
    /* Tamanho da primeira metade e segunda */
    int firstHalf = (mid - l) + 1, secondHalf = size - mid;
    int L[firstHalf], R[secondHalf];

    for (i = 0; i < firstHalf; i++)
        L[i] = v[l + i];

    for (j = 0; j < secondHalf; j++)
        R[j] = v[mid + 1 + j];

    i = 0, j = 0, k = l;

    while (i < firstHalf && j < secondHalf)
    {
        if (L[i] < R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[l] = R[j];
            j++;
        }
        k++;
    }

    while (i < firstHalf)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < secondHalf)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *v, int l, size_t size)
{
    if (l < size)
    {
        int mid = l + (size - l) / 2;

        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, size);

        // 2 valores nas duas metades
        merge(v, l, mid, size);
    }
}
