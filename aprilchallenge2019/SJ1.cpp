#include<bits/stdc++.h>
using namespace std;

vector< vector < int > > grafo;
int n;

long long v[100005];
long long m[100005];

vector < pair< int, int> > sol;

void bfs(int u, int pai, long long GCDacumulado){
	bool leaf = true;
	long long gcd = __gcd(GCDacumulado, v[u]);
	
	for(int i=0;i<grafo[u].size(); i++){
		if(grafo[u][i] != pai){
			bfs(grafo[u][i], u, gcd);
			leaf = false;
		}
	}
	
	if(leaf){
		sol.push_back( make_pair(u,  m[u] - gcd ) );
	}
}


int main()
{
	int t; cin >> t;
	while(t--){
		cin >> n;
		grafo.resize(n+1);
		
		for(int i=0;i<n-1;i++){
			int a, b;
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		
		for(int i=1;i<=n;i++){
			cin >> v[i];
		}
		for(int i=1;i<=n;i++){
			cin >> m[i];
		}
		
		bfs(1, -1, v[1]);
		
		sort(sol.begin(), sol.end());
		
		for(int i=0;i<sol.size();i++){
			if(i) cout << " " << sol[i].second;
			else cout << sol[i].second;
		}		
		cout << endl;
		
		grafo.clear();
		sol.clear();		
	}
}
