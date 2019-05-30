// Dado um valor N, mostre os próximos 5 múltiplos de N.

#include <stdio.h>
int main(){
    int n;
    scanf ("%d", &n);
    for (int i = 2; i <= 6; i++){
        printf ("%d\n", i*n);
    } 
}
