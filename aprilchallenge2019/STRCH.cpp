#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		char c; cin >> c;

		int last = -1;
		long long cont = 0;
		for(int i=0;i<s.size();i++){
			if(s[i] == c){
				cont+= (i+1)*(n-i) - (last+1)*(n-i);
				last = i;
			}
		}

		cout << cont << endl;

	}
}
