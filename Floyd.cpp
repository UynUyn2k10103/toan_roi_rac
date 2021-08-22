#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int> > a, d, next1;

void print(int u, int v){
    if(u == v) {
        cout << u << "->" << v;
        return;
    }

    if(next1[u][v] == -1){
        cout << "khong co duong di";
        return;
    }
    queue <int> st;

    while (u != v){
        st.push(u);
        u = next1[u][v];
    }

    while (!st.empty()){
        cout << st.front() << "->";
        st.pop();
    }

    cout << v;
    

}

void Floyd(){
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = a[i][j];
            if(a[i][j] != 1e9) next1[i][j] = j;
            else next1[i][j] = -1;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    next1[i][j] = next1[i][k];
                } 
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << "---------------\n";
        for(int j = 1; j <= n; j++) {
            cout << "Chi phi di tu dinh " << i << " den dinh " << j << " la: " << d[i][j] << "\n";
            print(i, j);
            cout << "\n";
        }
    }
}

void solve(){
    cin >> n;
    a.clear();
    d.clear();
    next1.clear();

    a.resize(n + 1, vector <int> (n + 1));
    d.resize(n + 1, vector <int> (n + 1));
    next1.resize(n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(!a[i][j]) a[i][j] = 1e9;
        }
    }
    Floyd();
}

int main(){
    solve();
}