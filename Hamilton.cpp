#include <bits/stdc++.h>
using namespace std;

int n, s;
vector <vector <int> > G;
vector <bool> vs;
vector <int> res;

void print(){
    cout << s << " ";
    for(int i = 0; i < res.size(); i ++) 
        cout << res[i] << " ";
    cout << s << " ";
    cout << "\n";
    return;
}

void Hamilton(int u){
    for(int i = 0; i < G[u].size(); i++){
        
        int v = G[u][i];

        if(res.size() == n - 1 && v == s){
            print();
            return;
        }

        if(!vs[v]){
            vs[v] = 1;
            res.push_back(v);
            Hamilton(v);
            res.pop_back();
            vs[v] = 0;
        }
    }
}

void solve(){
    cin >> n >> s;
    G.clear(); vs.clear();
    G.resize(n + 1); vs.resize(n + 1, 0);
    res.clear();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }

    vs[s] = 1;
    Hamilton(s);
}

int main(){
    solve();
}