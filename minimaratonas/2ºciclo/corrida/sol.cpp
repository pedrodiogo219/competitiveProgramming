#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt{
	ll x, y;
	bool operator < (pt aux) const {
		return x!=aux.x ? x<aux.x : y<aux.y;
	}
};

int main(){
	
	pt v[3];
	for(int i=0; i<3; i++)
		scanf("%lld %lld", &v[i].x, &v[i].y);
	
	sort(v, v+3);
	
	ll maiory=INT_MIN, menory=INT_MAX;
	for(int i=0; i<3; i++){
		maiory = max(maiory, v[i].y);
		menory = min(menory, v[i].y);
	}
	
	ll answer = 2LL*(v[2].x - v[0].x)*(maiory-menory);//retangulo que envolve os 3 pontos

	if( (v[0].y >= v[1].y && v[1].y >= v[2].y) || 
		(v[0].y <= v[1].y && v[1].y <= v[2].y) ){//y ordenados
		
		answer-= abs(v[0].x-v[1].x)*abs(v[0].y - v[1].y) +
				 abs(v[1].x-v[2].x)*abs(v[1].y - v[2].y) + 
				 abs(v[0].x-v[2].x)*abs(v[0].y - v[2].y) +
				 2LL*min( abs(v[1].x - v[0].x)*abs(v[1].y-v[2].y), 
					  abs(v[1].x - v[2].x)*abs(v[1].y-v[0].y));		
	}else{
		answer-= abs(v[0].x-v[1].x)*abs(v[0].y - v[1].y) + 
				 abs(v[1].x-v[2].x)*abs(v[1].y - v[2].y) + 
				 abs(v[0].x-v[2].x)*abs(v[0].y - v[2].y);
	}
	
	printf("%lld\n", answer);
}
