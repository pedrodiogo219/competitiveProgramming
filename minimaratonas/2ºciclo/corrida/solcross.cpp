#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt{
	ll x, y;
	bool operator < (pt aux) const {
		return x!=aux.x ? x<aux.x : y<aux.y;
	}
	
	pt operator - (pt a){
		return {x-a.x, y-a.y};
	}
};

ll cross(pt a, pt b){
	return abs(a.x*b.y - a.y*b.x);
}

int main(){
	
	pt v[3];
	for(int i=0; i<3; i++)
		scanf("%lld %lld", &v[i].x, &v[i].y);
	
	printf("%lld\n", cross(v[0]-v[1], v[0]-v[2]));
}
