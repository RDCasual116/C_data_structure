#include<stdio.h>
#include<stdlib.h>
typedef struct vector {
 int* v;
 int v_size;
 int vm_size;
}vect;

vect* create_vector() {
 vect* ret = (vect*)malloc(sizeof(vect));        
 ret->v = (int*)malloc(2*sizeof(int));
 ret->v_size = 0;
 ret->vm_size = 2;
 return ret;
}

vect* arrtovec (int arr[], int size) {
 vect* ret = (vect*)malloc(sizeof(vect));
 ret->v=arr;
 ret->v_size=size;
 ret->vm_size=1+size;
 return ret;
}

void v_push(vect *v, int ins) {
 if (v->v_size == v->vm_size) {
  int* new_memory = (int*)realloc(v->v, 2 * v->vm_size* sizeof(int));
  v->v = new_memory;
  v->vm_size *= 2;
 }
 v->v[v->v_size] = ins;
 v->v_size++;
}

void v_pop(vect* v) {
 if (v->v_size > 0) {
  v->v_size--;         
 }
 else{
  printf("Vector is already empty\n");
 }
}


void free_vector(vect* v) {
 if (v) {
  free(v->v);
  free(v);
 }
}

int main() {
 int arr[]={3,6,2,1,9,6};
 vect* rd=arrtovec(arr,6);
 for(int i=0;i<6;i++){
printf("%d ",rd->v[i]);
}
}
