#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

//2- Calcular a média e o desvio padrão dos dados de um vetor.

int main(){

    int n;
    scanf("%d", &n);

    int vet[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    double soma = 0.0;

    #pragma omp parallel
    {
        #pragma omp for reduction (+:soma)
        for(int i=0;i< n; i++) 
        { 
            soma += vet[i];   
        }
    }

    double media = (double)soma/(double)n;

    printf("media: %lf\n", media);
    soma = 0.0;

    #pragma omp parallel
    {
        #pragma omp for reduction (+:soma)
        for(int i=0;i< n; i++) 
        { 
            soma += pow(vet[i] - media, 2);
        }
    }

    double desvioPadrao;

    desvioPadrao = sqrt(soma/n);

    printf("desvio padrao: %lf\n", desvioPadrao);


    return 0;
}

//schedule