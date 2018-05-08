
#include <stdlib.h>
#include "swap.h"
#include "isort.h"




void merge(int *arr, int l, int m, int r){

	int i,j,k;
	int ll = m-l+1;
	int rr = r-m;
	int BL[ll];
	int BR[rr];

	for (i = 0; i < ll; i++)
        BL[i] = arr[l + i];
    	
    for (j = 0; j < rr; j++)
        BR[j] = arr[m + j +1 ];
    	

    i = 0; 
    j = 0; 
    k = l; 

    while (i < ll && j < rr)
    {
        if (BL[i] <= BR[j])
        {
            arr[k] = BL[i];
            i++;
        }
        else
        {
            arr[k] = BR[j];
            j++;
        }
        k++;
    }
      while (i < ll)
    {
        arr[k] = BL[i];
        i++;
        k++;
    }
 
    while (j < rr){
        arr[k] = BR[j];
        j++;
        k++;
  }}

void mergesort(int *arr ,int l, int r) {
	int m;
   	
   	if(l < r) {
    	m = (l + r) / 2;

      	mergesort(arr,l, m);
      	mergesort(arr,m+1, r);
      	merge(arr,l, m, r);
   }
    else { 
     	return;
   }   
}