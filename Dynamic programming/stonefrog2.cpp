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
/* https://www.lqdoj.edu.vn/problem/stonefrog2 */   
const int N = 1e5 + 97; 
int a[N], dp[N]; 
void solve(){
    int n, k; 
    cin >> n >> k; 
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
    } 
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + abs(a[i - 1] - a[i]); 
        for(int j = 2; i - j > 0 && j <= k; j++){
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j])); 
        }
    } 
    cout << dp[n]; 
}