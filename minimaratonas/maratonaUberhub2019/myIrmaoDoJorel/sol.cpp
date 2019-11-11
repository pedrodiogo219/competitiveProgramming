#include <bits/stdc++.h>
using namespace std;
 
int n;
bool flag=0;
	
int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int x;
			scanf("%d", &x);
			if(i == j) {
				if(flag) printf(" ");
				printf("%d", (int)sqrt(x));
				flag = true;
			}
		}
	}
	puts("");
}