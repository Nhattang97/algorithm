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
/* https://www.lqdoj.edu.vn/problem/capdoi */ 
#define int long long
int n, s, a[1000001];
int binary_search(int left, int right,int value){
    int tmp = left - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid] <= value){
            tmp = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return tmp;
}
void solve(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i < n; i++){
        int value = s - a[i];
        int x = binary_search(i + 1, n, value);
        int y = binary_search(i + 1, n, value - 1);
        ans += x - y;
    }
    cout << ans;
}