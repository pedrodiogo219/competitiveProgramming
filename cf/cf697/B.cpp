#include<bits/stdc++.h>
using namespace std;

int vet[1000100];


int main(){
    vet[2020] = 1;
    vet[2021] = 1;
    int N = 1000000;

    
    for (int i = 2022; i <= N; i++ ){
        if ( vet[i - 2020] == 1 || vet[i-2021] == 1){
            vet[i] = 1;
        }
    }   

    int t; scanf("%d", &t);

    int a;
    while(t--){
        scanf("%d", &a);
        if (vet[a]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}