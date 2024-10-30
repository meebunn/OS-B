#include <stdio.h>
#include <stdlib.h>

int stack_mem(int x) {
  printf("Local address of %d is at %p\n", x, (void*)&x);
  if (x == 0) return 0;
  return stack_mem(x - 1);
}

/// declare global variable 
int a =1 ; 
int b =2212 ;
int c =4112 ;

int main(void) {
  
  stack_mem(2); //call function to create local variable

  // heap (dynamically allocated memory) 
  int* h1 = (int*)malloc(sizeof(int));
  printf("Heap Address 1 :  %p\n", (void*)h1);
  int* h2 = (int*)malloc(sizeof(int));
  printf("Heap Address 2 : %p\n", (void*)h2);
  int* h3 = (int*)malloc(sizeof(int));
  printf("Heap Address 3 :  %p\n", (void*)h3);
  //global variable
  printf("Global Address of (a) : %p\n", (void*)&a);
  printf("Global Address of (b) : %p\n", (void*)&b);
  printf("Global Address of (c) : %p\n", (void*)&c);
  //free memmory
  free(h1) ; 
  free(h2);
  free(h3) ;

  return 0;

}