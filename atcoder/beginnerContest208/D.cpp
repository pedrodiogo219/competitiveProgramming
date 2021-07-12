#include<bits/stdc++.h>
using namespace std;

int dist[410][410];
#define INF 0x3f3f3f3f


int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i ++){
        for( int j = 0; j<= n; j++){
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
        }
    }

    int a, b, c;
    for(int i = 0; i < m; i++){
        // printf("lendo uma vez");
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
    }



    long long sum = 0;
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            };
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dist[i][j] != INF){
                    sum += dist[i][j];
                }
            }
        }
    }

    printf("%lld\n", sum);

}