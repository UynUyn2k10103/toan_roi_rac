#include <bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define fori(i,a,b) for (ll i = a; i < b; i++)
#define forr(i,a,b) for (ll i = a - 1; i >= b; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

const ll mod = 1e9 + 7;
const ll oo = 1e6 + 5;

int n, s;
vector <vector <int> > G, a;

void Euler(int u){
    stack <int> CE, st;
    st.push(u);
    bool ok;
    while (!st.empty()){
        u = st.top(); 
        ok = 1;
        for(int i = 1; i <= n; i++){
            if(a[u][i]){
                ok = 0;
                a[u][i] = 0;
                a[i][u] = 0;
                st.push(i);
                break;
            }
        }
        if(ok) {
            CE.push(u);
            st.pop();
        }
    }

    while (!CE.empty()){
        cout << CE.top() << " ";
        CE.pop();
    }
    
    
}

vector <bool> vs;

void BFS(){
    int u = 1;
    queue <int> q;
    q.push(u);
    vs[u] = 1;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < G[u].size(); i ++){
            int v = G[u][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
            }
        }
    }
}

void check(){
    vs.clear();
    vs.resize(n + 1, 0);
    BFS();

    for(int i = 1; i <= n; i++){
        if(vs[i] == 0) {
            cout << "Deo lien thong dau ma doi Euler";
            return;
        }
    }
    int bacle = 0;
    for (int i = 1; i <= n; i++) if(G[i].size() % 2) bacle++;
    if(bacle > 2) {
        cout << "Khong ton tai euler";
    }

    if(bacle == 0){
        cout << "Chu trinh euler";
    }
    else cout << "Duong di euler";
    cout << "\n";
    Euler(s);
}

void solve(){
    cin >> n >> s;
 
    G.clear();
    a.clear();
    
    G.resize(n + 1);
    a.resize(n + 1, vector <int> (n + 1));

    for(int i = 1; i <= n; i++){
        //a[i].resize(n + 1);
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]) G[i].push_back(j);
        }
    }

    check();
}



int main(){
    solve();
}