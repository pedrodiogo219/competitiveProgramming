#include<bits/stdc++.h>
using namespace std;


string s, r;

int memo[100][100][100][100];
bool pal(int a, int b){
	if(a > b) return true;
	if(a == b) return true;
	
	//if(memo[a][b] != -1) return memo[a][b];
	
	return  r[a] == r[b] and pal(a+1, b-1);
}


int dp(int a, int b, int x, int y){
	if(b>=x || x > y || b < a) return 0;
	if(a < 0 || y > s.size()-1) return 0;
	
	if(memo[a][b][x][y] != -1) return memo[a][b][x][y];
	
	printf("(%d, %d)  (%d, %d)\n", a, b, x, y);
	
	r = "";
	for(int i=a;i<=b;i++){
		r+=s[i];
	}
	for(int i=x; i<=y; i++){
		r+=s[i];
	}
	
	return memo[a][b][x][y] =   pal(0, r.size()-1) + 
				    dp(a, b-1, x, y) +
				    dp(a, b, x+1, y) + 
				    dp(a+1, b, x, y) + 
				    dp(a, b, x, y-1) +  
				    dp(a, b+1, x, y) +
				    dp(a, b, x-1, y);
}

int main(){
	while(true){
		memset(memo, -1, sizeof(memo));
		cin >> s;
		cout <<  dp(0, s.size()/2-1, s.size()/2, s.size()-1) << endl;
	}
	
}
