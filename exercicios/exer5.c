#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

/*
    5- Retornar todos os valores primos de 0 até N.
        Válido;
        Balanceado;
        Otimizado.

    Crivo de erastótenes
*/

int main(){

    int n;
    scanf("%d", &n);

    double tdata = omp_get_wtime();

    int raizN = (int) sqrt(n);

    //int vet[n];

    char* vet = (char*) malloc(n * sizeof(char));

    #pragma omp parallel
    {
        #pragma omp for
        for(int i=0; i<n; i++){
            vet[i] = 0;
        }
    }

/*
    Marcações do vetor: 
        0: não passou ainda
        1: é primo
        2: nao é primo
*/

    vet[0] = 2;
    for(int i = 1; i<=raizN; i ++){
        if(vet[i] == 0){
            vet[i] = 1;
        } else {
            continue;
        }
        #pragma omp parallel//
        {//
            #pragma omp for//
            for(int j = i; j<n; j += i+1){
                if(vet[j] == 0){
                    vet[j] = 2;
                }
            }
        }//
    }

    tdata = omp_get_wtime() - tdata;

/*
    sem paralelizacao: time: 
    com paralelizacao: time: 
*/


    printf("time: %lf secs\n\n",tdata);

    /*
    printf("Numeros primos: \n");
    for(int i=0; i<n; i++){
        if(vet[i] != 2){
            printf("%d  ", i+1);
        }    
        //printf("%d  ", vet[i]); 
    }
    printf("\n");*/

    return 0;
}