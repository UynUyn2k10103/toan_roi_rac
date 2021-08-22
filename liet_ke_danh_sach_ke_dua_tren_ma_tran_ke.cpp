#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int> > G;

// do thi vo huong
void Danh_Sach_Ke(){
    for(int u = 1; u < G.size(); u++){
        cout << "danh sach ke cua dinh " << u << " la: ";
        for(int j = 0; j < G[u].size(); j++){
            cout << G[u][j]<< " ";
        }
        cout << "\n";
    }
}

// do thi co huong

int main(){
    // đầu vào là ma trận kề
    G.clear();
    
    cin >> n;
    G.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x) {
                G[i].push_back(j);
            }
        }
    }

	//for(int i = 0; i < G.size(); i ++) cout << G[i].size() << " ";
    Danh_Sach_Ke();
}