#include <bits/stdc++.h>
using namespace std;

int n, s;
vector <vector<int> > a;
vector <int> d;
vector <bool> vs;
vector <int> truoc;

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

void Dijktra(){

    for(int v = 1; v <= n; v ++){
        d[v] = a[s][v];
        truoc[v] = s;
    }

    vs[s] = 1;
    int u = s;
    d[s] = 0;

    while(1){ // T khác rỗng, T là tập đỉnh chưa thăm trong V;
        int minn = 1e9;

        for(int i = 1; i <= n; i++){
            if(minn > d[i] && !vs[i]){
                u = i;
                minn = d[i];
            }
        }

        if(vs[u]) break; // tham het cac dinh

        vs[u] = 1;
        for(int v = 1; v <= n; v++){
            if(d[v] > d[u] + a[u][v] && !vs[v] && a[u][v]){
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << "Duong di ngan nhat tu dinh " << s << "den dinh " << i << " la: " << d[i] << "\n";
        print(i);
        cout << "\n";
    }

    
}

void solve(){
    cin >> n >> s;

    truoc.clear();
    truoc.resize(n + 1);

    vs.clear();
    vs.resize(n + 1, 0);
    a.clear();
    a.resize(n + 1, vector <int> (n + 1));

    d.clear();
    d.resize(n + 1, 0);

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(!a[i][j] && i != j) a[i][j] = 1e9;
        }
    }

    Dijktra();
}

int main(){
    solve();
}