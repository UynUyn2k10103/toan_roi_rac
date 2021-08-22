#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> ra, vao;

int main(){
    cin >> n;
    ra.clear();
    vao.clear();
    ra.resize(n + 1, 0);
    vao.resize(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool x;
            cin >> x;
            if(x){
                ra[i] ++;
                vao[j] ++;
            }
        }
    }

    cout << "ban bac ra: \n";
    for(int i = 1; i <= n; i++) cout << "deg+ " << i << " = " << ra[i] << "; ";
    cout << "\nban bac vao: \n";
    for(int i = 1; i <= n; i++) cout << "deg- " << i << " = " << vao[i] << "; ";
    
}