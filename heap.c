#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size==0){
     return NULL;
  }else{
    return pq->heapArray[0].data;
  }
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac){
    pq->capac=pq->capac*2+1;
    pq->heapArray=realloc(pq->heapArray,pq->capac);
  }
  pq->heapArray[pq->size+1].priority=priority;
  pq->heapArray[pq->size+1].data=data;
  int aux=pq->size;
  int parent=(aux-1)/2;
  while(pq->heapArray[parent].priority<pq->heapArray[aux].priority){
    heapElem tmp=pq->heapArray[parent];
    pq->heapArray[parent]=pq->heapArray[aux];
    pq->heapArray[aux]=tmp;
    aux=parent;
    parent=(aux-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* nuevo=(Heap*)malloc(sizeof(Heap));
  nuevo->heapArray=(heapElem*)malloc(3*sizeof(heapElem));
  nuevo->size=0;
  nuevo->capac=3;
   return nuevo;
}
