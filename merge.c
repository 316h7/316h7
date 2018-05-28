#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include<stddef.h>
#include "mergesort.h"

int compare_int (const void * a, const void * b)
{	

    int _a = *(int*)a;
    int _b = *(int*)b;
    // _a = _a - '0';
    // _b = _b - '0';
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

struct string {
  void *ptr;
  int k;
  int size;
  int a;
};

struct string getstring(void);

struct string getstring(void){
   struct string s;
   int k=0,j=0;
   s.a=100;
FILE *fp;
   int i=0;
   char buf[256];
   char x[256];
   fp = fopen("file" , "rb");
   if(fp == NULL) {
      perror("Error opening file");
     
   }
  
      while (fscanf(fp, " %1023s", buf) == 1){ //%1023s
      if (j<strlen(buf)) 
         j=strlen(buf);
         k++;
        
    }
  
   s.ptr=calloc(k,j);
   
      s.size=j;
      s.k=k;
 
     rewind(fp);

      printf("in_struct\n");
  while (fscanf(fp, "%1023s \n", x) == 1) {
      
        strcpy(s.ptr+i*s.size,x);     
        puts(s.ptr+i*s.size);
         i++;
               
  }
printf("end_of_struct");
   
   fclose(fp);
   fp=NULL;
   return s;
   }
  
int main ()
{

      

  char strings[4][20] = {"aaa", "ccc", "ddd", "eee"};
  int arr[10]={33,9,8,7,6,5,4,2,3,1};

  int strln=sizeof(strings);
  int bb= strlen(*strings);
 int sizef= sizeof(strings[0]);
 int total=strln/sizef;//sizef=sizeof(strings[0][0]);
 printf("%d,%d\n",total,sizef );
  
	char buf[100];
   struct string s;
 	s=getstring();
   



  msort(s.ptr, s.k, s.size, (int(*)(const void*, const void*))strcmp);
 
  
FILE *p;
  char newfilename[32];
  strcpy(newfilename, "file");
  strcat(newfilename, ".sorted");

  p = fopen(newfilename, "wb+");
   if (p == NULL)
    {
        printf("Could not open file");
        return 0;
    }

       for(int i=0;i<s.k; i++){

          memcpy(buf, s.ptr, s.size);
     	 s.ptr += s.size;
 
    	
     fprintf(p, "%s \n", buf); 
      }

    fclose(p);
   // p=NULL;
 //free(s.ptr);
  return 0;
}