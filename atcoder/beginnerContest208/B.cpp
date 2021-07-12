#include<bits/stdc++.h>
using namespace std;

long long int coins[11];

int main(){

    coins[0] = 1;
    for (int i = 1; i <= 10; i++){
        coins[i] = coins[i-1] * i;
    }

    int ammount = 0;
    long long P; scanf("%lld", &P);
    
    for (int i = 10; i >= 1; i--){
        if (P >= coins[i]){
            if (P >= coins[i] * 100){
                P -= coins[i]*100;
                ammount += 100;
            }else{
                ammount += P/coins[i];
                P = P%coins[i];
            }
        }
    }

    printf("%d\n", ammount);


}