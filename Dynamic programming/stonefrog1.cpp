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
/* https://www.lqdoj.edu.vn/problem/stonefrog1 */
const int N = 1e5 + 97; 
int a[N], dp[N]; 
void solve(){
    int n; cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
    }  
    dp[0] = a[0] = 1e9; 
    for(int i = 2; i <= n; i++){
        int one = dp[i - 1] + abs(a[i - 1] - a[i]); 
        int two = dp[i - 2] + abs(a[i - 2] - a[i]); 
        dp[i] = min(one, two);  
    } 
    cout << dp[n]; 
}
