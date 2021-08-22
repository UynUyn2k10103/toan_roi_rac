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

void xl (){
    char c;
    vector <long long> f;
    f.resize(10,0);
    long long dem = 0;
    while (cin >> c){
        f[c - '0'] ++;
        dem ++;
    }
    int tmp = -1;

    for(int i = 0; i < 10; i++){
        if(f[i] % 2){
            if(dem % 2 == 0){
                cout << "NO";
                return;
            }
            else{
                if(tmp == -1){
                    tmp = i;
                }
                else{
                    cout << "NO";
                    return;
                }
            }
        }
    }
    for(int i = 9; i >= 0; i--){
        if(i == tmp) continue;
        for(int j = 0; j < f[i] / 2; j++){
            cout << i;
        }
    }
    if(tmp != -1) cout << tmp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < f[i] / 2; j++){
            cout << i;
        }
    }
    
}

int main(){
    fastIO();
    int T; 
    T = 1;
    //cin.ignore();
    while (T -- ){
        xl();
        cout << "\n";
    }
}