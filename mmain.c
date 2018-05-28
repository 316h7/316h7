    #include<stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdlib.h>
    #include "mergesort.h"

int compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}




int main(int argc, char const *argv[]){

    int tab[8] = {68,24,1,56,57,32,12,8};

 char array[7][10] = {"fff","bbb","aaa","zzz","ddd","sss","ccc"};

printf("Int array: \n");

    for(int i = 0; i < 8; i++)
       printf("%d ", *(tab+i));
       printf(" \n");

{
    msort(tab, 8, sizeof(int), (int(*)(const void*, const void*))compare);
 printf("Int array after sorting:");
        printf(" \n");
for(int i = 0; i < 8; i++)
       printf("%d ", *(tab+i));

printf("\n\n Char array: \n");

     for (int i = 0; i < 7; i++) {
        printf ("%d: %s.\n", i, array[i]);
    }
    msort(array, 7, 10, (int(*)(const void*, const void*))strcmp);

printf("\n Char array after sorting: \n");

 for (int i = 0; i < 7; i++) {
        printf ("%d: %s.\n", i, array[i]);
    }

	return 0;
}
}
