#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

//3- Calcular a média harmônica de um vetor.

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
            soma += 1.0/vet[i];   
        }
    }

    double mediaHarmonica;
    mediaHarmonica = (double)n / soma;

    printf("media harmocia: %lf\n", mediaHarmonica);
    
    return 0;
}