#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int> > G;
vector <bool> vs;
vector <pair <int, int> > T;

void CayKhung_DFS(int u){
    vs[u] = 1;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!vs[v]){
            T.push_back(make_pair(u, v));
            CayKhung_DFS(v);
        }
    }
}

void BFS(int u){
    queue <int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
                T.push_back(make_pair(u, v));
            }
        }
    }
    
}

void solve(){
    cin >> n;
    G.clear();
    G.resize(n + 1);
    vs.clear();
    vs.resize(n + 1, 0);
    T.clear();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }

    //CayKhung_DFS(1);
    BFS(1);
    for(int i = 0; i < T.size(); i++) cout << T[i].first << " " << T[i].second << "\n";
}

int main(){
    solve();
}