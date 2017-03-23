#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
void insertionSort(int data[]);
void selectionSort(int data[]);
void bubbleSort(int data[]);
void shellSort(int data[]);
void moveDown(int *data, int first, int last);
void heapSort(int data[]);
void mergeSort(int data[], int p, int r);
void merge(int *a, int p, int q, int r);
void quickSort (int v[], int p, int r);
int separa(int *v, int p, int r);
void swap(int i, int j, int *vet);
int main(){
    int i;
    int vet[MAX];
    
    srand(time(NULL));
    
    for(i=0 ; i<MAX ; i++){
        vet[i] = rand() % 100;
    }
    
    printf("VETOR DE NUMEROS GERADOS\n");
    for(i=0;i<MAX;i++){
        printf("%i ", vet[i]);
    }
    
    //insertionSort(vet);
    //selectionSort(vet);
    //shellSort(vet);
    //bubbleSort(vet);
    //heapSort(vet);
    //mergeSort(vet, 0, MAX);
    quickSort(vet, 0, MAX);
    
    return 0;
}
void insertionSort(int data[]){
    int i, j;
    
    for (i=1; i<MAX; i++){
        int tmp = data[i];
        for (j=i; j>0 && tmp < data[j-1]; j--){
            data[j] = data[j-1];   
        }
        data[j] = tmp;
    }
}
void selectionSort(int data[]){
    int i, j, least;
    
    for (i=0; i<MAX-1; i++){
        for (j=i+1, least=i; j<MAX; j++)
            if (data[j] < data[least])
                least = j;
        swap(least, i, data);
    }
    
    printf("\nVETOR ORDENADO PELO ALGORITMO SELECTIONSORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", data[i]);
    }
    
}
void bubbleSort(int data[]){
    int i, j;
    
    for (i=0; i < MAX-1; i++){
        for (j = MAX-1; j>i; --j){
             if (data[j] < data[j-1]){
                 swap(j, j-1, data);
             }
        }
    }
    
    printf("\nVETOR ORDENADO PELO ALGORITMO BUBBLESORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", data[i]);
    }
}
void shellSort(int data[]){
    int i, j, hCnt, h, k;
    int incrementos[20];
    
    for(h=1,i=0; h<MAX ; i++){
        incrementos[i] = h;
        h = 3*h + 1;
    }
    
    for(i--;i>=0;i--){
        h = incrementos[i];
        
        for(hCnt=h ; hCnt< 2*h ; hCnt++){
            for(j=hCnt; j<MAX; ){
                int tmp = data[j];
                k = j;
                while(k-h>=0 && tmp < data[k-h]){
                    data[k] = data[k-h];
                    k-=h;
                }
                data[k] = tmp;
                j+=h;
            }
        }
    }
    
    printf("\nVETOR ORDENADO PELO ALGORITMO SHELLSORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", data[i]);
    }
    
}
void moveDown(int *data, int first, int last){
    int largest = 2*first + 1;
    
    while(largest <= last){
        if(largest < last && data[largest] < data[largest+1])
            largest++;
        if(data[first] < data[largest]){
            swap(first, largest, data);
            first = largest;
            largest = 2*first + 1;
        } else {
            largest = last + 1;
        }
    }
}
void heapSort(int data[]){
    int i;
    
    for(i=MAX/2-1;i>=0;--i){
        moveDown(data, i, MAX-1);
    }
    
    for(i=MAX-1;i>=1;--i){
        swap(0, i, data);
        moveDown(data, 0, i-1);
    }
    
    printf("\nVETOR ORDENADO PELO ALGORITMO HEAPSORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", data[i]);
    }
    
}
void merge(int *a, int p, int q, int r) {
    int i, j, k;
    int aux[MAX];
    
    for (i = q+1; i > p; i--){
        aux[i-1] = a[i-1];   
    }
    
    for (j = q; j < r; j++){
        aux[r+q-j] = a[j+1];   
    }
    
    for (k = p; k <= r; k++){
        if (aux[j] < aux[i]){
            a[k] = aux[j--];  
        } 
        else{
            a[k] = aux[i++];   
        }
    }
}
void mergeSort(int data[], int p, int r) {
    int i;
    
    if (p < r) {
       int q = (p + r) / 2;
       mergeSort(data, p, q);  
       mergeSort(data, q+1, r);
       merge(data, p, q, r);
    }
    
    /*printf("\nVETOR ORDENADO PELO ALGORITMO MERGESORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", data[i]);
    }*/
}
void quickSort (int v[], int p, int r){
   int j, i;
   
   if (p < r) {
      j = separa (v, p, r);
      quickSort (v, p, j-1);
      quickSort (v, j+1, r);
   }
   
   printf("\nVETOR ORDENADO PELO ALGORITMO QUICKSORT\n");
    for(i=0;i<MAX;i++){
        printf("%i ", v[i]);
    }
   
}
int separa(int *v, int p, int r){
    int c = v[p], i = p+1, j = r, t;
    
    while (i <= j) {
        if (v[i] <= c){
            ++i;  
        }
        else if (c < v[j]){
            --j;    
        }
        else {
            t = v[i], v[i] = v[j], v[j] = t;
            ++i;
            --j;
        }
   }
   v[p] = v[j];
   v[j] = c;
   return j; 
}
void swap(int i, int j, int *vet){
    int aux;
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}