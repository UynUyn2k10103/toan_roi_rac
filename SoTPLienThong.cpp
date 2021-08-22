#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > G;
vector <bool> vs;
int n;

void BFS(int u){
    queue <int> q;
    q.push(u);
    vs[u] = 1;
    // for(int i = 1; i <= n; i++) if(vs[i]) cout << i << " ";
    // cout << "tmp" << u;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < G[u].size(); i ++){
            int v = G[u][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
                // if(v == 8){
                //     for(int i = 1; i <= n; i++) if(vs[i]) cout << i << " ";
                //     cout << "**";
                // }
            }
        }
    }
}

int main(){
    // đầu vào là ma trận kề
    G.clear();
    vs.clear();
    cin >> n;
    vs.resize(n + 1, 0);
    int lien_thong = 0;
    G.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vs[i]) {
            BFS(i);
            lien_thong ++;
        }
    }
    cout << "So thanh phan lien thong cua do thi la: " << lien_thong;
}