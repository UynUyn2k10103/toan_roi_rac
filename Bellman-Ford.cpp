#include <bits/stdc++.h>
using namespace std;

vector <int> d, truoc;
int n, s;
vector <vector <int> > a;

void print(int u){
    stack <int> st;

    while (u != s){
        st.push(u);
        u = truoc[u];
    }

    cout << s;

    while (!st.empty()){
        cout << "->" << st.top();
        st.pop();
    }
    

}

void Bellman_Ford(){
    for(int i = 1; i <= n; i++){
        d[i] = a[s][i];
        truoc[i] = s;
    }

    d[s] = 0;

    for(int k = 1; k <= n - 2; k++){
        for(int v = 1; v <= n; v ++){
            if(v == s) continue;
            for(int u = 1; u <= n; u++){
                if(d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << "Chi phi di tu dinh " << s << " den dinh " << i << " la: " << d[i] << "\n";
        print(i);
        cout << "\n";
    }

}

void solve(){
    cin >> n >> s;
    a.clear();
    d.clear();
    truoc.clear();

    a.resize(n + 1, vector <int> (n + 1));
    d.resize(n + 1);
    truoc.resize(n + 1);

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(!a[i][j]) a[i][j] = 1e9;
        }
    }
    Bellman_Ford();
}

int main(){
    solve();
}