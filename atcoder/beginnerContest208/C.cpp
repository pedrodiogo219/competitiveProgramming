#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n, k;
    scanf("%lld %lld", &n, &k);

    vector< pair< long long int, long long int> > v;

    long long int a;
    for (int i =0 ; i < n; i++){
        scanf("%lld", &a);
        v.push_back( pair<long long int, long long int>(a, i) );
    }

    sort(v.begin(), v.end());


    long long int sol[200100];
    for (int i = 0; i < n; i++) sol[i] = k/n;
    long long int restantes = k%n;
    for (auto p: v){
        // printf("(%lld %lld)\n", p.first, p.second);
        if (restantes > 0){
            sol[p.second] += 1;
            restantes--;
        }
    }

    for(int i = 0; i < n; i++){
        if (i) printf(" ");
        printf("%lld", sol[i]);
    }
    printf("\n");

}