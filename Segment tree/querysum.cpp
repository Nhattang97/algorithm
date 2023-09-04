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
/* https://www.lqdoj.edu.vn/problem/querysum */    
#define int long long 
const int N = 1e5 + 97; 
int st[4 * N]; 
void update(int root, int left, int right, int index, int value){
    if (index < left || right < index) return; 
    if (left == index && index == right){
        st[root] += value; 
        return; 
    } 
    int mid = (left + right) >> 1; 
    update(root << 1, left, mid, index, value); 
    update(root << 1 | 1, mid + 1, right, index, value); 
    st[root] = st[root << 1] + st[root << 1 | 1];
}
int get(int root, int left, int right, int start, int finish){
    if (finish < left || right < start) return 0; 
    if (start <= left && right <= finish) return st[root]; 
    int mid = (left + right) >> 1; 
    int sum_left = get(root << 1, left, mid, start, finish); 
    int sum_right = get(root << 1 | 1, mid + 1, right, start, finish); 
    return sum_left + sum_right; 
}
void solve(){
    int n, q; 
    cin >> n >> q; 
    for(int i = 1; i <= n; i++){
        int value; cin >> value; 
        update(1, 1, n, i, value); 
    } 
    while (q--){
        int type, x, y; 
        cin >> type >> x >> y; 
        if (type == 1) update(1, 1, n, x, y); else 
            cout << get(1, 1, n, x, y) << "\n"; 
    }
}