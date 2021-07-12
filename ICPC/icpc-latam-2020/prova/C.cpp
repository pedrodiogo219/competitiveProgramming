#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f

long long int vet[100100];
long long int sobra[100100];
long long int falta[100100];

int main(){
    int n; 
    scanf("%d", &n);
    long long sum = 0;
    long long int target;
    
    for (int i = 0; i < n; i++){
        scanf("%lld", &vet[i]);
        sum+=vet[i];
    }
    target = sum/n;


    for (int i = 0; i < n; i++){
        sobra[i] = 0;
        falta[i] = 0;
        if (vet[i] >= target){
            sobra[i] = vet[i] - target;
        }
        if (vet[i] <= target){
            falta[i] = target - vet[i];
        }
    }

    long long int bestCusto = INF;

    long long int mochila = 0LL;
    long long int custo = 0LL;

    for (int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            
            if (sobra[i] > 0){
                mochila += sobra[i];
                sobra[i] = 0;
            }

            if (falta[i] > 0){
                int valorQueDa = min(mochila, falta[i]);
                mochila -= valorQueDa;
                falta[i] -= valorQueDa;
            }

            // printf("i: %d\nmochila: %d\n", i, mochila);

            custo += mochila;
        }
    }

    // printf("custo direita %d\n", custo);

    bestCusto = min(custo, bestCusto);


    for (int i = 0; i < n; i++){
        sobra[i] = 0;
        falta[i] = 0;
        if (vet[i] >= target){
            sobra[i] = vet[i] - target;
        }
        if (vet[i] <= target){
            falta[i] = target - vet[i];
        }
    }
    mochila = 0;
    custo = 0;

     for (int j = 0; j < 2; j++){
        for(int i = n-1; i >= 0; i--){
            if (sobra[i] > 0){
                mochila += sobra[i];
                sobra[i] = 0;
            }

            if (falta[i] > 0){
                int valorQueDa = min(mochila, falta[i]);
                mochila -= valorQueDa;
                falta[i] -= valorQueDa;
            }
            custo += mochila;

            // printf("i: %d\nmochila: %d\n", i, mochila);
        }
    }

    // printf("custo esquerda %d\n", custo);
    bestCusto = min(custo, bestCusto);
    printf("%lld\n", bestCusto);

    return 0;
}