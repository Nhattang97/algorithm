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
/* https://www.lqdoj.edu.vn/problem/lis */ 
const int N = 1e6 + 97;  
int a[N], tmp[N], dp[N]; 
int tknp(int l, int r, int val){
    int res = 0; 
    while (l <= r){
        int m = (l + r) >> 1; 
        if (tmp[m] < val){
            res = m; 
            l = m + 1;
        } else r = m - 1; 
    } 
    return res; 
}
void solve(){
    int n; cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        tmp[i] = INT_MAX; 
    } 
    int m = 0, ans = 1; 
    for(int i = 1; i <= n; i++){
        int j = tknp(1, m, a[i]) + 1; 
        dp[i] = j;  
        if (m < j) m = j; 
        ans = max(ans, dp[i]);
        tmp[j] = min(tmp[j], a[i]);        
    }  
    cout << ans; 
}