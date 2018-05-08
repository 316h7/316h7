#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "msort.h"

void merge(int *arr, int l, int m, int r);
void mergesort(int *arr ,int l, int r);




int main(int argc, char const *argv[])
{	int n = 10;
	int l;
	int a[n];
	int r = sizeof(a) / sizeof(int);
	printf("List size \n %d \n", r );

  printf("List before sorting \n");
   
  
     //  for(int i = 0; i < 10; i++){
   		// a[i] = 10-i;
     //  printf("%d ", a[i]);}	
     //  printf("\n");

   for(int i = 0; i < n; i++){
   		a[i] = rand() % 1000000 + 19;
      printf("%d ", a[i]);}

	
 	mergesort(a, 0, r-1); 

printf(" \n");
printf("List after sorting \n");
	 for(int i = 0; i < r; i++)
       printf("%d ", a[i]);

printf(" \n");  

	return 0;
}
