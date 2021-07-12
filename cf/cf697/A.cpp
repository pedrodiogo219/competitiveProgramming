#include<bits/stdc++.h>
using namespace std;

int main(){


    int t; scanf("%d", &t);
    while(t--){
        long long int n;
        scanf("%lld", &n);

        while( n%2 == 0  && n >= 2){
            n/=2;
        }
        if (n > 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }
}