#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > G;
vector <bool> vs;
int n;

void DFS(int u){

    stack <int> st;
    st.push(u);
    vs[u] = 1;
    cout << u << " ";

    while(!st.empty()){
        u = st.top(); st.pop();
    
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(!vs[v]){
                cout << v << " ";
                vs[v] = 1;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
}

void BFS(int u){
    queue <int> q;
    q.push(u);
    vs[u] = 1;
    while(!q.empty()){
        u = q.front(); q.pop();
        cout << u << " ";
        for(int i = 0; i < G[u].size(); i ++){
            int v = G[u][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
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
    G.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }

    BFS(1);
}