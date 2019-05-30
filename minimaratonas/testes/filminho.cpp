#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='X'){
			cout << i << endl;
			return 0;
		}
	}
	
	cout << s.size() << endl;
}
