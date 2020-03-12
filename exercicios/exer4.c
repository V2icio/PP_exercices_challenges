#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

#define NUM_THREADS 8
//4- Encontrar o maior e o menor valor de um vetor.

int main(){
    int n;
    scanf("%d", &n);

    int vet[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    int bigger[NUM_THREADS];
    int smaller[NUM_THREADS];
    omp_set_num_threads(NUM_THREADS);

    /* 
        Colocar os primeiros valores do vetor nos vetores de
        maior e menor p/ não ter problema com a comparação.
    */
    for(int i = 0; i < NUM_THREADS; i++){ 
        bigger[i] = vet[i];
        smaller[i] = vet[i];
    }

    #pragma omp parallel 
    {
        #pragma omp for
        for(int i = NUM_THREADS; i < n; i++){
            int a = omp_get_thread_num();
            if(bigger[a] < vet[i]){
                bigger[a] = vet[i];
            } else if(smaller[a] > vet[i]){
                smaller[a] = vet[i];
            }
        }
    }

    int maior, menor;

    maior = bigger[0];
    menor = smaller[0];
    for(int i = 1; i<NUM_THREADS; i++){
        if(bigger[i] > maior){
            maior = bigger[i];
        } else if(smaller[i] < menor){
            menor = smaller[i];           
        }
    }

    printf("maior: %d\n", maior);
    printf("menor: %d\n", menor);

    return 0;
}