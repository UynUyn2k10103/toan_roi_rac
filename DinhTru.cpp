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

int V, E;
vector < vector <int> > G;
int lien_thong, so_dinh_tru;
vector <bool> vs;

void BFS(int u){
	queue <int> q;
	q.push(u);
	vs[u] = 1;
	while(!q.empty()){
		u = q.front(); q.pop();
		fori(i, 0, G[u].size()){
			int v = G[u][i];
			if(vs[v] == 0){
				vs[v] = 1;
				q.push(v);
			}
		}
	}
}

void Dinh_tru(int u){
	vs.clear();
	vs.resize(V + 1, 0);
	vs[u] = 1;
	int dem  = 0;
	fori(i, 1, V + 1){
		if(vs[i] == 0) {
			dem ++;
			BFS(i);
		}
	}
	//cout << u << " " << dem << " " << lien_thong <<"\n";
	if(dem > lien_thong) {
        cout << u << " ";
        so_dinh_tru ++;
    }
}

void xl (){
	cin >> V;
	lien_thong = 0;
	int u, v;
	G.clear();
	G.resize(V + 1);
	
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            bool x;
            cin >> x;
            if(x) G[i].push_back(j);
        }
    }
	vs.clear();
	vs.resize(V + 1, 0);

	fori(i, 1, V + 1){
		if(vs[i] == 0) {
			lien_thong ++;
			BFS(i);
		}
	}
    so_dinh_tru = 0;
    cout << "Cac dinh tru cua do thi la: \n";
	fori(i, 1, V + 1){
		Dinh_tru(i);
	}
    cout << "\nSo dinh tru cua do thi la: " << so_dinh_tru;
}

int main(){
	xl();
}