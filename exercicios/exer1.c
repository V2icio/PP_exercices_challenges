#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>


//1- Dados 2 vetores, calcular a soma deles.

int main(){
    
    int n;

    scanf("%d", &n);
    int vet1[n],vet2[n];

    for(int i = 0; i<n; i++){
        scanf("%d", &vet1[i]);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &vet2[i]);
    }
    
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < n; i++){
            vet2[i] = vet2[i] + vet1[i];
        }  
    }

    for(int i=0; i<n; i++){
        printf("%d  ", vet2[i]);
    }
    printf("\n");


    return 0;
}