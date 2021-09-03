/**********
Descricao: Funcoes auxiliares para criação do MergeSort
**********/
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>

void generate(int *v, size_t size);
void generateCrescente(int *v, size_t size);
void generateDecrescente(int *v, size_t size);
void printArray(int *v, size_t size);
void swap(int *a, int *b);
#ifdef __cplusplus
}
#endif
#endif