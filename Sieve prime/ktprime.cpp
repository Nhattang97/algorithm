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
/* https://www.lqdoj.edu.vn/problem/ktprime */   
#define int long long

bool prime_1(int n){
    if (n < 4) return n > 1;
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

bool prime_2(int n){
    if (n < 4) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int pow_1(int a, int b, int n){
    int r = 1;
    while (b > 0){
        if (b % 2) r = r * a % n;
        a = a * a % n;
        b /= 2;
    }
    return r;
}
bool check_1(int s, int d, int n, int a){
    if (n == a) return true;
    int p = pow_1(a, d, n);
    if (p == 1) return true;
    for(; s > 0; --s) {
        if (p == n - 1) return true;
        p = p * p % n;
    }
    return false;
}
bool miller_1(int n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    int s = 0, d = n - 1;
    while (d % 2 == 0) ++s, d /= 2;
    int num[] = {2, 7, 61};
    for(int i = 0; i < 3; i++)
    if (!check_1(s, d, n, num[i])) return false;
    return true;
}

int mul_2(int a, int b, int n){
    int r = 0;
    while (b > 0){
        if (b % 2) r = (r + a) % n;
        a = (a + a) % n;
        b /= 2;
    }
    return r;
}
int pow_2(int a, int b, int n){
    int r = 1;
    while (b > 0){
        if (b % 2) r = mul_2(r, a, n);
        a = mul_2(a, a, n);
        b /= 2;
    }
    return r;
}
bool check_2(int s, int d, int n, int a){
    if (n == a) return true;
    int p = pow_2(a, d, n);
    if (p == 1) return true;
    for(; s > 0; --s) {
        if (p == n - 1) return true;
        p = mul_2(p, p, n);
    }
    return false;
}
bool miller_2(int n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    int s = 0, d = n - 1;
    while (d % 2 == 0) ++s, d /= 2;
    int num[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int i = 0; i < 9; i++)
    if (!check_2(s, d, n, num[i])) return false;
    return true;
}

void solve(){
    int n; cin >> n; 
    if (prime_1(n)) cout << "YES"; else cout << "NO";
    /* 
    if (prime_2(n)) cout << "YES"; else cout << "NO";
    if (miller_1(n)) cout << "YES"; else cout << "NO";
    if (miller_2(n)) cout << "YES"; else cout << "NO"; 
    */
}