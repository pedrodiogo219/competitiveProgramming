#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string s;
	cin >> s;
	bool flag = true;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'X'){
			cout << i << endl;
			flag = false;
			break;
		}
	}	
	
	if(flag) cout << s.size() << endl;
}
