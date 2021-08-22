#include <bits/stdc++.h>
using namespace std;

int n, s, V;
vector <vector <int> > G;

vector <bool> vs;
vector <pair<int, int> > T;

void Prim(){
    vs[s] = 1;
    int dh = 0;
    V = n;
    while(--V){
        int e = 1e9, u, v;

        for(int i = 1; i <= n; i++){ // lay 1 dinh thuoc VH vs[i] == 1
            if(!vs[i]) continue;
            for(int j = 1; j <= n; j++) { // lay 1 dinh thuoc V vs[i] = 0;
                if(!vs[j] && (G[i][j] < e || (e != 1e9 && G[i][j] == e && i < u))){
                    u = i;
                    v = j;
                    e = G[i][j];
                }
            }
        }
        if(e == 1e9) {
            cout << "do thi khong co cay khung";
            return;
        }
        
        dh += e;
        vs[v] = 1;
        T.push_back(make_pair(u, v));

    }
    for(int i = 0; i < T.size(); i++) cout << T[i].first << " " << T[i].second << "\n";
    cout << "do dai cay khung " << dh;
}

void solve(){
    cin >> n >> s;

    T.clear();

    G.clear();
    G.resize(n + 1, vector <int> (n + 1));

    vs.clear(); vs.resize(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
            if(!G[i][j]) G[i][j] = 1e9;
        }
    }
    Prim();

}

int main(){
    solve();
}
/*
13
1
0 2 1 3 0 0 0 0 0 0 0 0 0
2 0 2 0 0 5 5 0 0 0 0 0 0
1 2 0 4 0 5 0 0 0 0 0 0 0
3 0 4 0 5 5 0 0 0 0 0 0 0
0 0 0 5 0 6 0 0 0 6 0 0 0
0 5 5 5 6 0 6 6 6 6 0 0 0
0 5 0 0 0 6 0 6 0 0 0 0 0
0 0 0 0 0 6 6 0 7 0 0 7 7
0 0 0 0 0 6 0 7 0 7 7 0 0
0 0 0 0 6 6 0 0 7 0 7 7 0
0 0 0 0 0 0 0 0 7 7 0 8 0
0 0 0 0 0 0 0 7 0 7 8 0 8
0 0 0 0 0 0 0 7 0 0 0 8 0
*/