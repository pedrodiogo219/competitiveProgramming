#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
vector< ii > v;
vector<ll> caiu;

ii llervalos[200100];

ll n, h;

int main(){
	scanf("%lld %lld", &n, &h);
	ll a, b;
	for(ll i = 0; i < n; i++){
		scanf("%lld %lld", &a, &b);
		llervalos[i] = make_pair(a,b);
	}
	llervalos[n] = make_pair(2000001000, 2000001000);

	v.push_back(make_pair(0, llervalos[0].first));
	caiu.push_back(- llervalos[0].first);

	ll pos = 0;
	for(ll i = 0; i < n; i++){
		v.push_back(llervalos[i]);
		caiu.push_back( caiu[caiu.size()-1] );

		v.push_back( make_pair(llervalos[i].second, llervalos[i+1].first) );
		caiu.push_back( caiu[caiu.size()-1] + llervalos[i].second - llervalos[i+1].first );
	}

	// for(ii eu : v){
	// 	printf("(%lld, %lld) ", eu.first, eu.second);
	// }
	// printf("\n");
	//
	// for(ll eu: caiu){
	// 	printf("%lld ", eu);
	// }
	// printf("\n");

	ll c, x, lo, hi, mid, ans;
	ll final_ans = -1;
	for(ll i = 0; i < n ; i++){
		//printf("to testanto pro llervalo (%d, %d)\n", llervalos[i].first, llervalos[i].second);
		c = caiu[i+i+1];
		x = c-h;
		//printf("c: %d\n x: %d\n", c, x);
		ans = -1;
		lo = 0, hi = caiu.size()-1;

		while(lo<=hi){
			mid = lo+(hi-lo)/2;
			if(caiu[mid]>x){
				lo = mid+1;
			}
			else{
				ans = mid;
				hi = mid-1;
			}
		}
		// printf("ans: %lld\n", ans);
		//printf("distancia que eu consigo: %d\n", (v[ans].second + caiu[ans] - x - llervalos[i].first));
		final_ans = max(final_ans, (v[ans].second + caiu[ans] - x - llervalos[i].first) );
	}

	printf("%lld\n", final_ans);

}
