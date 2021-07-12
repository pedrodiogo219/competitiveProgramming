#include<bits/stdc++.h>
using namespace std;

struct pa{
    int first, second;
    const bool inline operator < (pa aux){
        return ((double)first)/second > ((double)aux.first)/aux.second;
    }
};


pa p[200100];
int main(){
    int t; scanf("%d", &t);

    while(t--){

        int n, m; scanf("%d %d", &n, &m);
        int total = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &p[i].first);
        }

        for (int i = 0; i < n; i++){
            scanf("%d", &p[i].second);
        }

        sort(p, p+n);
        for (int i = 0; i < n; i++){
            printf("(%d %d)\n", p[i].first, p[i].second);
        }

        int gasto = 0;
        int pos = 0;
        while(m > 0 && pos < n){
            m -= p[pos].first;
            gasto += p[pos].second;
            pos++;
        }

        if (m > 0) printf("-1\n");
        else{
            printf("%d\n", gasto);
        }


    }
}