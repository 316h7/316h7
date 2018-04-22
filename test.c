#include <stdio.h>
#include <stdlib.h>
#include <time.h>




// void merge(int *a, int low, int mid, int high) {
  
//    int l1, l2, i;
//    int b[high];
//    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
//       if(a[l1] <= a[l2])
//          b[i] = a[l1++];
//       else
//          b[i] = a[l2++];
//    }
   
//    while(l1 <= mid)    
//       b[i++] = a[l1++];

//    while(l2 <= high)   
//       b[i++] = a[l2++];

//    for(i = low; i <= high; i++)
//       a[i] = b[i];
// }


void merge(int *arr, int l, int m, int r){

	int i,j,k;
	int ll = m-l+1;
	int rr = r-m;
	int BL[ll];
	int BR[rr];

	for (i = 0; i < ll; i++){
        BL[i] = arr[l + i];
    	printf("%d ", BL[i]);

    }printf(" ll \n");
    for (j = 0; j < rr; j++){
        BR[j] = arr[m + j +1 ];
    	printf("%d ", BR[j]);
    	
    }printf("rr \n ");

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

int main(int argc, char const *argv[])
{	int n = 50;
	int l;
	int a[n];
	int r = sizeof(a) / sizeof(int);
	printf("%d \n", r );

  printf("List before sorting \n");
   
  
     //  for(int i = 0; i < 10; i++){
   		// a[i] = 10-i;
     //  printf("%d ", a[i]);}	
     //  printf("\n");
   for(int i = 0; i <= n; i++){
   		a[i] = rand() % 100 + 1;
      printf("%d ", a[i]);}

	
 	mergesort(a, 0, r-1); 




	printf(" \n");
printf("List af sorting \n");
	 for(int i = 0; i < r; i++)
       printf("%d ", a[i]);

	return 0;
}
