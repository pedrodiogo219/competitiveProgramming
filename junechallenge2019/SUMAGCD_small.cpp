#include<bits/stdc++.h>
using namespace std;

int v[100];
int n;
int ans = 0;
#define INF 100000000


std::vector< int > grupoA , grupoB;
std::vector<int> solucaoA, solucaoB;
int calcula(int pos, int gcdA, int gcdB){
  if(pos == n){
    if(gcdA!=0 && gcdB!=0){

      // if(gcdA+gcdB > ans){
      //   ans = gcdA+gcdB;
      //   solucaoA = grupoA;
      //   solucaoB = grupoB;
      // }
      return gcdA+gcdB;
    }
    else return -INF;
  }


  //grupoA.push_back(v[pos]);
  int pegaA;
  if(gcdA != 0)
    pegaA = calcula(pos+1, __gcd(gcdA, v[pos]), gcdB);
  else
    pegaA = calcula(pos+1, v[pos], gcdB);

  //grupoA.pop_back();


  //grupoB.push_back(v[pos]);
  int pegaB;
  if(gcdB != 0)
    pegaB = calcula(pos+1, gcdA, __gcd(gcdB, v[pos]));
  else
    pegaB = calcula(pos+1, gcdA, v[pos]);

  //grupoB.pop_back();

  return max(pegaA, pegaB);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();


  int t; cin >> t;
  while(t--){

    cin >> n; int maiorzinho = 0;
    for(int i = 0; i < n ; i++){
      cin >> v[i];
      maiorzinho = max(maiorzinho, v[i]);
    }

    ans = 0;
    cout << calcula(0, 0, 0) << endl;

    if (solucaoB.size() < solucaoA.size()){
      swap(solucaoA, solucaoB);
    }


    bool flag = false;
    for(int i =0 ; i < solucaoA.size(); i++){
      if(solucaoA[i] == maiorzinho){
        flag = true;
      }
    }
    //
    // if(!flag) cout << "OLHA AQUIIIIIIII" << endl;
    //
    // cout << "solucao: ";
    // for(int i = 0; i < solucaoA.size(); i++){
    //   cout << solucaoA[i] << " ";
    // }
    // cout << "     ";
    // for(int i = 0; i < solucaoB.size(); i++){
    //   cout << solucaoB[i] << " ";
    // }
    // cout << endl;

  }


}
