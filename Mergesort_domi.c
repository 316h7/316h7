#include <stdio.h>  //postawowa biblioteka C (np. printf)
#include <stdlib.h> //zawiera np. rand - genernie liczb losowych
#include <time.h>   //biblioteka do operacji zwi¹zanych z czasem (np. clock)

//scala mniejsze tablice [l,m]+[m+1,r]=[l,r]
void merge(int *arr, int l, int m, int r){ //merge przyjmuje arr=tablica, l=pocz, m=œrod, r=koniec tablicy

	int i,j,k;       //i-element lewej podtablicy, j - element prawej podtablicy, k - element tablicy
	int ll = m-l+1; //ustalanie wielkoœci lewej podtablicy
	int rr = r-m;   //ustalanie wielkoœci prawej podtablicy
	int BL[ll];    //lewa podtablica
	int BR[rr];    //prawa postablica

	for (i = 0; i < ll; i++) //wype³nienie lewej podtablicy
        BL[i] = arr[l + i];

    for (j = 0; j < rr; j++) //wype³nienie prawej podtablicy
        BR[j] = arr[m + j +1 ];


    i = 0;
    j = 0;
    k = l;      //ustawianie podtablic i tablicy na pierwzy element

    while (i < ll && j < rr)  //sprawdzanie czy 1. lewy element jest mniejszy od prawego elementu
    {
        if (BL[i] <= BR[j])
        {
            arr[k] = BL[i]; //jak tak, przypisywanie go do tablicy
            i++;            //przechodzenie do klejnego
        }
        else                //jak nie, przypisywanie prawego elementu do tablicy
        {
            arr[k] = BR[j];
            j++;            //przechodzenie do kolejnego
        }
        k++;
    }
      while (i < ll)       //przepisanie wszystkich wartoœci po lewej stronie gdy siê skoñczy prawa
    {
        arr[k] = BL[i];
        i++;
        k++;
    }

    while (j < rr){       //przepisanie wszystkich wartoœci po prawej stronie gdy siê skoñczy lewa
        arr[k] = BR[j];
        j++;
        k++;
  }}

void mergesort(int *arr ,int l, int r) { //sortowanie tablicy arr, o pocz l i koñcu r
	int m;

   	if(l < r) {          //warunek na lew¹ mniejsz¹ od prawej
    	m = (l + r) / 2;  //deklaracja œrodka
//wywo³ania rekurencyjne - dzielenie do momentu l=r (stos)
      	mergesort(arr,l, m);    //dzielenie tablicy na pó³- lewa
      	mergesort(arr,m+1, r);  //dzielenie tablicy na pó³ - prawa
      	merge(arr,l, m, r);     //³¹czenie posortowanych podtablic
   }
    else {
     	return;
   }
}

int main(int argc, char const *argv[])
{	//int n = 10;
srand(time(NULL));
int n = (rand() % 15) + 3;
	int l;
	int a[n];
	int r = sizeof(a) / sizeof(int); //ustalanie wielkoœci tablicy
	printf("%d \n", r );

  printf("List before sorting \n");


     //  for(int i = 0; i < 10; i++){
   		// a[i] = 10-i;
     //  printf("%d ", a[i]);}
     //  printf("\n");

//srand((int)time(0));
   for(int i = 0; i < n; i++){
   		a[i] = rand() % 100 + 1; //generowanie tablicy liczb pseudolosowych od 1do100
      printf("%d ", a[i]);}


 	mergesort(a, 0, r-1);

printf(" \n");
printf("List after sorting \n");
	 for(int i = 0; i < r; i++)
       printf("%d ", a[i]);

	return 0;
}
