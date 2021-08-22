#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > G;
vector < vector <bool> > a;
vector <bool> vs;
int n;

bool BFS(int u){
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
    for(int i = 1; i <= n; i++) 
        if(!vs[i]) return 0;
    return 1;
}

bool DFS(int u){
    vs.clear();
    vs.resize(n + 1, 0);
    stack <int> st;
    st.push(u);
    vs[u] = 1;
    while (!st.empty()){
        u = st.top();
        st.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(!vs[v]){
                vs[v] = 1;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) 
        if(!vs[i]) return 0;
    return 1;
      
}

void weakly_Connected(){
    vs.clear();
    vs.resize(n + 1, 0);

    G.clear();
    G.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]) G[i].push_back(j);
        }
    }
    if(DFS(1)) cout << "\n_____Do thi lien thong yeu_____";
    else cout << "\n____Do thi khong lien thong____";
}

void Strongly_Connected(){
    cout << "____Do thi duyet qua cac dinh:_____\n ";
    for (int i = 1; i <= n; i++){
        if(DFS(i)) cout << i << " ";
        else {
            cout << i;
            weakly_Connected();
            return;
        }
    }
    cout << "\n________Do thi lien thong manh____________";
}

int main(){
    // đầu vào là ma trận kề
    G.clear();
    vs.clear();
    a.clear();

    cin >> n;
    
    a.resize(n + 1, vector <bool> (n + 1, 0));
    int lien_thong = 0;
    G.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) {
                G[i].push_back(j);
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }
    Strongly_Connected();

    //cout << "So thanh phan lien thong cua do thi la: " << lien_thong;
}