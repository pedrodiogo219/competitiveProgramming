#include<bits/stdc++.h>
using namespace std;

int vo[200010];
int va[200010];
map<int, int> os;
map<int, int> as;
// int os[200100];
// int as[200100];
long long int total = 0;
int a, b, k;
int aux;

int main(){

    int t; scanf("%d", &t);
    while(t--){
        os.clear();
        as.clear();
        // for (int i = 0; i < a; i++) os[i] = 0;
        // for (int i = 0; i < b; i++) as[i] = 0;
 
        scanf("%d %d %d", &a, &b, &k);

        for (int i = 0; i < k; i++){
            scanf("%d", &aux);
            os[aux]++;
            vo[i] = aux;
        }

        for (int i = 0; i < k; i++){
            scanf("%d", &aux);
            as[aux]++;
            va[i] = aux;
        }

        total = 0;
        for(int i = 0; i < k; i++){
            total += (k - 1) - (os[vo[i]] - 1) - (as[va[i]] - 1);
        }

        printf("%lld\n", total/2);

    }
}