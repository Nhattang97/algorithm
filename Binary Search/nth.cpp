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
/* https://www.lqdoj.edu.vn/problem/nth */
#define int long long 
int search(int a, int b, int n){
    int l = 1, r = 1e18; 
    int tmp = l - 1, lcm = a * b / __gcd(a, b); 
    while (l <= r){
        int m = (l + r) / 2; 
        if (m / a + m / b - m / lcm >= n){
            tmp = m; 
            r = m - 1;
        } else l = m + 1;
    } 
    return tmp; 
} 
void solve(){
    int t; cin >> t; 
    while (t--){
        int a, b, n; 
        cin >> a >> b >> n; 
        cout << search(a, b, n) << "\n"; 
    }
}