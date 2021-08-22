#include <bits/stdc++.h> 
using namespace std;

struct node{
    int w, u, v;
};

struct cmp{
    bool operator ()(node a, node b){
        if(a.w == b.w){
            if(a.u == b.u) return a.v > b.v;
            return a.u > b.u;
        }
        return a.w > b.w;
    }
};

int n, so;
vector <pair <int, int> >T;
priority_queue <node, vector <node>, cmp > q;
vector <int> Root;

int Find_Root(int u)
{
    while(Root[u] > 0){
        u = Root[u];
    }
    return u;
}

void Union(int r1, int r2){
    int x = Root[r1] + Root[r2];
    if(Root[r1] > Root[r2]){
        Root[r2] = x;
        Root[r1] = r2;
    }
    else{
        Root[r2] = r1;
        Root[r1] = x;
    }
}

void Kruskal(){
    int dh = 0;
    Root[q.top().u] = -1;
    while (!q.empty() && T.size() < n - 1){
        node u = q.top(); q.pop(); 

        int r1 = Find_Root(u.u);
        int r2 = Find_Root(u.v);
        if(r1 != r2){
            Union(r1, r2);
            T.push_back(make_pair(u.u, u.v));
            dh += u.w;
        }
    }

    if(T.size() < n - 1) {
        cout << "Do thi khong lien thong";
        return;
    }

    cout << "dh = " << dh << "\n";
    for(int i = 0; i < T.size(); i++){
        cout << T[i].first << " " << T[i].second << "\n";
    }
    
}

void solve(){
    T.clear();
    Root.clear();
    cin >> n;

    Root.resize(n + 1, -1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> so;
            if(so && j > i) q.push({so, i, j});
        }
    }

    Kruskal();
}

int main(){
    solve();
}
/*
7
0 2 3 1 0 0 0
2 0 2 0 0 3 0
3 2 0 1 4 5 6
1 0 1 0 2 0 0
0 0 4 2 0 0 7
0 3 5 0 0 0 4
0 0 6 0 7 4 0
*/
