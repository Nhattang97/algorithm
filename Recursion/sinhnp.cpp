#include <bits/stdc++.h> 
using namespace std; 
void solve(); 
signed main(){  
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    if (fopen("input.inp", "r")){
        freopen("input.inp", "r", stdin); 
        freopen("output.out", "w", stdout); 
    } 
    int q = 1; 
    if (!q) cin >> q; 
    while (q--) solve();  
    return 0 ^ 0;
}   
/* https://www.lqdoj.edu.vn/problem/sinhnp */
int n, bit[100];
void write(){
    for(int i = 1; i <= n; i++){
        cout << bit[i];
    }
    cout << "\n";
}
void dq(int i){
    if (i > n) write(); else {
        bit[i] = 0;
        dq(i + 1);
        bit[i] = 1;
        dq(i + 1);
    }
}
void QHD(){
    for(int i = 0; i < 1 << n; i++){
        for(int j = n; j > 0; j--){
            bit[j] = i >> (j - 1) & 1;
            cout << bit[j];
        }
        cout << "\n";
    }
}
void solve(){
    cin >> n;
    // dq(1);
    QHD();
}