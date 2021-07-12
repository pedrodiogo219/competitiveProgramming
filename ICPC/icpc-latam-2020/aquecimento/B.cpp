#include<bits/stdc++.h>
using namespace std;

string s;

string process(string s){
    bool plusFlag = false;
    bool arrobaFlag = false;

    string result = "";
    for (char c: s){
        if (arrobaFlag){
            result+=c;
            continue;
        }
        else{
            if (c == '@'){
                arrobaFlag = true;
                result += c;
                continue;
            }

            if (c == '.'){
                continue;
            }
            
            if (c == '+'){
                plusFlag = true;
                continue;
            }

            if (!plusFlag){
                result += c;
            }
        }        
    }

    return result;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n; cin >> n;

    set<string> SS;
    for(int i = 0; i < n; i++){
        cin >> s;

        SS.insert(process(s));
    }

    cout << SS.size() << endl;


    return 0;
}