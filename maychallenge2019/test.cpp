#include<bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(20);
	s.insert(45);
	s.insert(01);	

	set<int>::iterator it;	
	
	for(it = s.begin(); it != s.end(); it++){
		cout << '\t' << *it;
	}
	cout << endl;
}
