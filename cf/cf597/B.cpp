#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; scanf("%d", &t);

  int rs, ps, ss, a, b, c;
  int n;
  char s[1000];
  while(t--){
    scanf("%d", &n);
    scanf("%d %d %d",&a, &b, &c);
    scanf("%s", s);

    rs = 0;
    ss = 0;
    ps = 0;
    for(int i = 0; i < strlen(s); i++){
      if(s[i] == 'R') rs++;
      if(s[i] == 'P') ps++;
      if(s[i] == 'S') ss++;
    }

    int sobraR = 0, sobraP = 0, sobraS = 0;

    int ganho = 0;
    ganho += min(rs, b);
    ganho += min(ps, c);
    ganho += min(ss, a);

    sobraR = max(0, a - ss);
    sobraP = max(0, b - rs);
    sobraS = max(0, c - ps);

    if(ganho < (n/2 + (n%2 != 0) ) ){
      printf("NO\n");
    }else{
      printf("YES\n");
      for(int i = 0 ; i < strlen(s); i++){

        if(s[i] == 'R'){
          if(b > 0){
            printf("P");
            b--;
          }
          else{
            if(sobraP > 0){
              printf("P");
              sobraP--;
            }
            else if(sobraR > 0){
              printf("R");
              sobraR--;
            }
            else if(sobraS > 0){
              printf("S");
              sobraS--;
            }
          }
        }

        if(s[i] == 'P'){
          if(c > 0){
            printf("S");
            c--;
          }
          else{
            if(sobraP > 0){
              printf("P");
              sobraP--;
            }
            else if(sobraR > 0){
              printf("R");
              sobraR--;
            }
            else if(sobraS > 0){
              printf("S");
              sobraS--;
            }
          }
        }

        if(s[i] == 'S'){
          if(a > 0){
            printf("R");
            a--;
          }
          else{
            if(sobraP > 0){
              printf("P");
              sobraP--;
            }
            else if(sobraR > 0){
              printf("R");
              sobraR--;
            }
            else if(sobraS > 0){
              printf("S");
              sobraS--;
            }
          }
        }

      }
      printf("\n");
    }
  }
}
