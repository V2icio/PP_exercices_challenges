#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>
#include <map>
#include <list>
#include <string.h>
#include <string>

using namespace std; 
/*
    abundancia = todos os multiplos com ele mesmo somadas dividido por ele mesmo
    achar quem tem a mesma abundancia = amigos

    Encontrar todos os números amigos até n
*/

int gcd(int a, int b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
} 
/*
void simplificaFracao(int a, int b, int *vet){
    int gcdValue = gcd(a,b);

    vet[0] = a/gcdValue;
    vet[1] = b/gcdValue;
}*/

void calculaAbundancia(int n, int *aux){
    int soma;
    soma = 0;
    int max = (int)n/2;

    for(int i=1; i<=max; i++){
        if(n % i == 0){
            soma+=i;
        }
    }
    soma+=n;
    
    aux[0] = soma;
    aux[1] = n;
}


int main(){
    int n;
    scanf("%d", &n);

    double *vetAbundancia = (double*) malloc(n * sizeof(double));

    #pragma omp parallel
    {
        #pragma omp for
        for(int i=1; i < n; i++){
            int aux[2];
            calculaAbundancia(i, aux);
            //simplificaFracao(aux[0], aux[1], aux);
            double a;
            a = (double)aux[0]/(double)i;

            vetAbundancia[i] = a;        
        }
    }
     
        for(int i=1; i<n; i++){
            for(int j = i+1; j<n ; j++){
                if(vetAbundancia[i] == vetAbundancia[j]){
                    printf("%d %d sao amigos com indice %lf\n",i, j, vetAbundancia[i]);
                }
            }
        }


    return 0;
}
