#include <bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define fori(i,a,b) for (ll i = a; i < b; i++)
#define forr(i,a,b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ull unsigned long long
#define endl "\n"
using namespace std;

int v, st, ed, m, n, u;
vector <vector <int> > G;
vector <bool> visit;
vector <int> trace;
bool ok;

void res(){
    stack <int> s;
    s.push(ed);
    while(ed != st){
        ed = trace[ed];
        s.push(ed);
    }
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }
}

void BFS(){
    queue <int> q;
    u = st;
    q.push(u);
    visit[st] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        fori(i, 0, G[u].size()){
            v = G[u][i];
            if(visit[v] == 0) {
                visit[v] = 1;
                q.push(v);
                trace[v] = u;
            }
            if(v == ed){
                ok = 0;
                res();
                return;
            }
        }
    }

}

void DFS(){
    stack <int> s;
    s.push(st);
    visit[st] = 1;
    while (!s.empty()){
        u = s.top(); s.pop();
        fori(i,0,G[u].size()){
            v = G[u][i];
            if(visit[v] == 0){
                //cout << v << " ";
                visit[v] = 1;
                s.push(u);
                s.push(v);
                trace[v] = u;
                if(v == ed){
                    ok = 0;
                    res();
                    return;
                }
                break;
            }
        }
    }
}

void xl(){

    G.clear();
    visit.clear();
    trace.clear();

    cin >> n >> st >> ed; 

    G.resize(n + 1);
    visit.resize(n + 1, 0);
    trace.resize(n + 1, 0);
    
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << "dinh ke cua dinh " << i << "la: ";
    //     for(int j = 0; j < G[i].size(); j ++) cout << G[i][j] << " ";
    //     cout << endl;
    // }
    //for(int i = 0; i < G[3].size(); i++) cout << G[3][i] << " ";

    ok = 1;
    // duyet theo j thi call o day
    //cout << "DFS path: "; DFS(); 
    cout << "BFS path: "; BFS();
    if(ok) cout << "-1";
    

}
int main (){
    xl();
}