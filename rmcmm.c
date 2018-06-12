#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct string getstring(const char*filename);
void rmcmm(char *s);


struct string {
  char * ptr;
  int n;
  int size;
};


struct string getstring(const char*filename){

   struct string s;

   s.size=256;
   s.n=0;
   char buf[s.size];
   int i=0;




  FILE *fp;
 
  
   fp = fopen(filename , "rb");
   if(fp == NULL) {
      perror("Error opening file");
     
   }

   while ( fgets(buf, 255 , fp) != NULL )  ++s.n;

   s.ptr=(char*)malloc(s.n*s.size);

   rewind(fp);
    while ( fgets(buf, 255 , fp) != NULL ) {
  
     strcat(s.ptr, buf);
    //puts(s.ptr);
  }

  
  
   fclose(fp);
   fp=NULL;

   return s;
   }



void rmcmm(char *s)
{
    int i,j;
    for(i=j=0; s[j] ;  ){
      
        if ((s[j]=='\"' || s[j]=='\'') && s[j+1]){
          for(; s[j] && (s[j+1]!='\"' || s[j+1]!='\'');  ) 
          //while( s[j++] &&  s[j++]!='\"' || s[j++]!='\'')
             s[i++]=s[j++];
            }
        else if(s[j]=='/' && s[j+1] && s[j+1]=='/')
            for(j+=2; s[j] && s[j++]!='\n';  )  ;
        else if(s[j]=='/' && s[j+1] && s[j+1]=='*')
            for(j+=2; s[j] && s[++j] && (s[j-1]!='*' || s[j]!='/' || !j++ ); );//
        else
            s[i++]=s[j++];
    }
    s[i]='\0';
}



  
int main(int argc, char const *argv[]){


  // ARGUMENTS 
  
   if( argc == 2 )     
      printf("The argument supplied is %s\n", argv[1]);

   else if( argc > 2 ) {
      printf("Too many arguments. One argument expected.\n");
      printf("Usage: %s /path/to/file \n",argv[0] ); 
      return 1;
   }

   else {
      printf("One argument expected.\n");
      printf("Usage: %s /path/to/file \n",argv[0] ); 
      return 2;   
   }


  // FILENAME 

const char* filename;
filename=argv[1];


  // PERMISSIONS


  int f=access(filename, F_OK); 
  if(f==-1) {printf("Could not open file %s. File does not exist. \n",filename); return 3;}
  int r=access(filename, R_OK);
  if(r==-1) {printf("Cannot read from file %s. Permission denied. \n",filename); return 4;}


      
   struct string s;
 	 s=getstring(filename);

   // remove comments
    rmcmm(s.ptr);
    puts(s.ptr);
  return 0;
}