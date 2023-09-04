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
/* https://www.lqdoj.edu.vn/problem/primesnum */
const int N = 2e7 + 97; 
bool prime[N]; 
void sieve(int n){ 
    prime[0] = prime[1] = true; 
    for(int i = 2; i * i <= n; i++){
        if (!prime[i]){
            for(int j = i * i; j <= n; j += i){
                prime[j] = true; 
            }
        }
    }
}
void solve(){  
    sieve(10000000); 
    int l, r; 
    cin >> l >> r; 
    for(int i = l; i <= r; i++){
        if (!prime[i]){
            cout << i << "\n";
        }
    }
}