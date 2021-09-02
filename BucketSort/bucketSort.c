#include "bucketSort.h"
#include <stdio.h>

typedef struct Node
{
    float *data;
    struct Node *next;
} Node;

typedef struct Bucket
{
    Node *bucket;
    size_t size;
} Bucket;

typedef struct Node Bucket_it;

void swap(float *a, float *b)
{
    float *aux = b;
    b = a;
    a = aux;
}

Node *createNode(float *data)
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

Bucket *createBucket(size_t size)
{
    Bucket *bucket = malloc(sizeof(Bucket) * size);
    for (int i = 0; i < size; ++i)
    {
        bucket[i].bucket = NULL;
        bucket->size = 0;
    }
    return bucket;
}
void insertBucket(Bucket *bk, unsigned int index, float *data)
{
    Node *newNode = createNode(data);

    if (bk[index].bucket == NULL)
    {
        bk[index].bucket = newNode;
    }

    else
    {
        Bucket_it *it = bk[index].bucket;
        printf("bk[%d].size = %d\n", index, (int) bk[index].size);
        for(int i = 0; i < bk[index].size; i++){
            it = it->next;
        }
        it = newNode;
        it->next = NULL;
    }

    bk[index].size++;
}

void sort(Bucket *buckets, size_t size)
{
    int i, j;
    Node *aux;

    for (i = 0; i < size - i; ++i)
    {
        if (!buckets[i].bucket)
            continue;
        if (buckets[i].bucket->next)
        {
            Bucket_it *it = buckets[i].bucket->next;
            Node *aux = buckets[i].bucket;

            while (it != NULL)
            {
                if (aux->data > it->data)
                {
                    swap(aux->data, it->data);
                }
                it = it->next;
            }
        }
        else
        {
            if (buckets[i + 1].bucket)
            {
                if (buckets[i].bucket->data > buckets[i + 1].bucket->data)
                    swap(buckets[i].bucket->data, buckets[i + 1].bucket->data);
            }
        }
    }
}

void printBuckets(Bucket *bk, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        if (!bk[i].bucket)
            continue;
        else
        {
            if (bk[i].bucket->next)
            {
                Bucket_it *it = bk[i].bucket;
                for (int j = 0; j < bk[i].size; j++)
                {
                    printf("List: %.2f -> ", *(float *)it->data);
                    it = it->next;
                }
            }
            else
            {
                printf("%.2f -> ", *(float *)bk[i].bucket->data);
            }
        }
    }
}

void bucketSort(float *v, size_t size)
{
    /* The numbers in array is 0 to 1, i.e that the size of the indices buckets can be 0-10 */
    Bucket *buckets = createBucket(10);

    for (int i = 0; i < size; ++i)
    {
        int n = size * v[i];
        insertBucket(buckets, n, &v[i]);
    }

    sort(buckets, size);
    printBuckets(buckets, size);
}

int main()
{
    float v[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(v) / sizeof(v[0]);

    bucketSort(v, n);

    return 0;
}