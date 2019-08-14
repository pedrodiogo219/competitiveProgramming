#include <stdio.h>
#include <stdlib.h>

int main()
{
int n;
scanf("%d",&n);
    while(n+1)
    {
        printf("%d\n",n);
        n = n - 1;
    }
    return 0;
}
