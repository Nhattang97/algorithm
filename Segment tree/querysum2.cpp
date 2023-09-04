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
/* https://www.lqdoj.edu.vn/problem/querysum2 */ 
#define int long long
const int N = 1e5 + 97;
int a[N], st[4 * N], lazy[4 * N];
void build(int root, int left, int right){
    if (left > right) return;
    if (left == right){
        st[root] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(root * 2, left, mid);
    build(root * 2 + 1, mid + 1, right);
    st[root] = st[root * 2] + st[root * 2 + 1];
}
void down(int root, int left, int mid, int right){
    st[root * 2] += lazy[root] * (mid - left + 1);
    lazy[root * 2] += lazy[root];
    st[root * 2 + 1] += lazy[root] * (right - mid);
    lazy[root * 2 + 1] += lazy[root];
    lazy[root] = 0;
}
void update(int root, int left, int right, int start, int finish, int value){
    if (right < start || finish < left) return;
    if (start <= left && right <= finish){
        st[root] += (right - left + 1) * value;
        lazy[root] += value;
        return;
    }
    int mid = (left + right) / 2;
    down(root, left, mid, right);
    update(root * 2, left, mid, start, finish, value);
    update(root * 2 + 1, mid + 1, right, start, finish, value);
    st[root] = st[root * 2] + st[root * 2 + 1];
}
int get(int root, int left, int right, int start, int finish){
    if (right < start || finish < left) return 0;
    if (start <= left && right <= finish) return st[root];
    int mid = (left + right) / 2;
    down(root, left, mid, right);
    int sum_left = get(root * 2, left, mid, start, finish);
    int sum_right = get(root * 2 + 1, mid + 1, right, start, finish);
    return sum_left + sum_right;
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int x, y, value;
            cin >> x >> y >> value;
            update(1, 1, n, x, y, value);
        } else {
            int x, y;
            cin >> x >> y;
            int ans = get(1, 1, n, x, y); 
            cout << ans << "\n"; 
        }
    }
}