#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int MEMORIA = 1000;

void print_heap(int vetor[], int n){
    for (int x= 0; x < n; x++)
        {
            printf("%d ", vetor[x]);
        }
    puts("\n");
}

void subir(int i, int* vetor){
    int j = floor(i/2) ;//Considera-se o vetor inciando em 0.
    if (j>=0){
        if (vetor[i]>vetor[j]){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            subir(j, vetor);
        }
    }
    
}

void descer(int i, int n, int *vetor){
    int j = 2*i;
    if (j<=n){
        if (j<n){
            if (vetor[j+1]>vetor[j]){
                j++;
            }
            if (vetor[i]<vetor[j]){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            descer(j, n, vetor);
        }
        }
    }
}

void inserir(int valor, int *t, int* vetor){
    if (*t<=MEMORIA){
        vetor[*t] = valor;        
        subir(*t, vetor);
    }
    else{
        puts("Overflow");
    }
    (*t)++;
}

void remover(int n, int* t, int* vetor){
    if (n>=0){
        vetor[0] = vetor[*t-1];
        *t = *t-1;
        descer(0, *t, vetor);
    }
}
void construir(int* vetor, int t){
    for (int i = floor((t-1)/2); i >=0; i--)
    {
        descer(i, t, vetor);
    }
    
}
void heapsort(int* vetor, int t){
    construir(vetor, t);

    for (int i = t-1; i >= 1; i--)
    {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        descer(0, i-1, vetor);
    }
    
    
}
void insertion_sort(int* vetor, int tamanho){
    for (int  j= 1; j < tamanho; j++)
    {
        int chave = vetor[j];
        int i = j-1;
        while (i>=0 && vetor[i]>chave)
        {
            vetor[i+1]=vetor[i];
            i--;   
        }
        vetor[i+1] = chave;
    }

}




int main(){
    int size = 1000000;
    int vector[1000000];
    
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % 1000; 
    }
    clock_t begin = clock();
    heapsort(vector, size);
    clock_t end = clock();
    double t1 = (double)(end - begin) / CLOCKS_PER_SEC;
    heapsort(vector, size);
    print_heap(vector, size);
    printf("\n%f", t1);
    clock_t begin2 = clock();
    insertion_sort(vector, size);
    clock_t end2 = clock();
    double t2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("\n%f", t2);
    return 0;
}

