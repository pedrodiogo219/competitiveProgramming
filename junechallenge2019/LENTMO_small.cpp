#include<bits/stdc++.h>
using namespace std;

void printa(vector<int> v){
  for(int i  = 0; i < v.size(); i++){
    if(i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie();
  // cout.tie();

  int t; cin >> t;
  while(t--){
    int n; cin >> n;

    std::vector<int> v;
    int aux;
    for(int i = 0; i < n; i++){
      cin >> aux;
      v.push_back(aux);
    }

    int k, x;
    cin >> k >> x;

    queue< pair< vector<int> , vector <int> > > fila;
    set< vector<int> > vis;
    vector<int> caminho;
    caminho.push_back(0);
    fila.push( {v, caminho} );
    vis.insert(v);
    long long ans = 0, tamanho = 1000000;
    vector<int> melhor_caminho;

    while( !fila.empty() ){
      vector<int> estado_atual = fila.front().first;
      vector<int> caminho_ate_agora = fila.front().second;
      fila.pop();

      long long soma = 0;
      for( auto e: estado_atual){
        soma+=e;
      }

      if(soma > ans || (soma == ans && caminho_ate_agora.size() < tamanho)){
        // cout << "entrei aqui " << endl;
        // printa(estado_atual);
        // for(int i = 0; i < caminho_ate_agora.size(); i++){
        //   for(int j = 0; j < n; j++){
        //     if(caminho_ate_agora[i] & (1<<j)) printf("%2d, ", j);
        //     else cout << " , ";
        //   }
        //   cout << ")" << endl;
        // }
        ans = soma;
        tamanho = caminho_ate_agora.size();
        melhor_caminho = estado_atual;
      }

      for(int mask = 0; mask < (1<<n); mask++){
        int cont = 0;
        for(int i = 0; i < 10; i++){
          if(mask & (1<<i)) cont++;
        }

        if(cont == k){
          vector<int> prox_estado = estado_atual;
          for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
              prox_estado[i] = estado_atual[i]^x;
            }
          }

          if(!(vis.find(prox_estado) != vis.end())){
            caminho_ate_agora.push_back(mask);
            fila.push({prox_estado, caminho_ate_agora});
            vis.insert(prox_estado);
          }
        }

      }
    }

    cout << ans << endl;
    // for(int i = 0; i < melhor_caminho.size(); i++){
    //   for(int j = 0; j < n; j++){
    //     if(melhor_caminho[i] & (1<<j)) printf("%2d, ", j);
    //     else cout << " , ";
    //   }
    //   cout << ")" << endl;
    //
    // int soma = 0;
    // for(int j = 0; j < n; j++){
    //   if(melhor_caminho[i] & (1<<j)){
    //     v[j] = v[j] ^ x;
    //   }
    //   soma+=v[j];
    //   printf("%2d, ", v[j]);
    // }
    // cout << " --- " << soma;
    // cout << endl;
    //
    // }


  }
}
