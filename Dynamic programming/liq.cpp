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
/* https://www.lqdoj.edu.vn/problem/liq */ 
const int N = 1e4 + 97; 
int a[N], dp[N]; 
void solve(){
    int n; cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
    } 
    int ans = 0; 
    for(int i = 1; i <= n; i++){
        dp[i] = 1; 
        for(int j = 1; j < i; j++){ 
            if (a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1); 
            } 
        }
        ans = max(ans, dp[i]); 
    } 
    cout << ans; 
}
