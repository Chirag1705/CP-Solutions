#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
// #define mod 1e9 + 7
const ll mod = 1e9 + 7;

ll inv(ll i) {
    if (i == 1) 
    return 1; 
    
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
    }

ll mod_add(ll a, ll b) {
    a = a % mod; 
    b = b % mod; 
    
    return (((a + b) % mod) + mod) % mod;
}


ll mod_mul(ll a, ll b, ll m = mod){
    a = a%m;
    b = b%m;

    return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m = mod){
    a = a%m;
    b = b%m;

    return((a - b) + m)%m;
}

// another binpow method
ll pw(ll a, ll b, ll m){
    if(b == 0)
        return 1;
    
    if(b%2==0){
        ll t = pw(a, b/2, m);
        return (1LL * t * t % m);
    }
    else{
        ll t = pw(a, (b-1)/2, m);
        t = (1LL * t * t)%m;
        return (1LL * a * t % m);
    }
}

ll mod_div(ll a, ll b, ll m = mod){
    a = a%m;

    ll inv_b = pw(b, m-2, m);
    // inverse of b = b^m-2%m, only for prime m

    ll res = a*inv_b % m;

    return res;
}

// binary exponentiation
// binpow
// O(log(b))
ll modulo(ll a, ll b, ll n = mod){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
// binpow again
ll pwr(ll a, ll b) {
    a %= mod; 
    ll res = 1; 

    while (b > 0) {
        if (b & 1) 
            res = res * a % mod; 
        a = a * a % mod; 
        b >>= 1;
    } 
        return res;
}



void solve(){
        ll n;
        cin >> n;

        vt<ll>arr(n), v(n), arr2;
        string s, s1;

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        arr2 = arr;
        v = arr;
        sort(v.begin(), v.end());

        cin >> s;
        s1 = s;
        ll cntN = 0, cntS = 0;

        for(ll i = 0; i < n; i++){
            if(s[i] == 'S')
                cntS++;
            else
                cntN++;
        }

        if(arr == v){
            cout << "0" << "\n";
            return;
        }

        if(s[0] != s[n-1]){
            cout << "1" << "\n";
            return;
        }

        if(cntS == 0 or cntN == 0){
            cout << "-1" << "\n";
            return;
        }

        ll var1 = INT_MAX, var2 = INT_MIN;
        bool ok1 = false, ok2 = false;

        for(ll i = 0; i < n; i++){
            if(arr[i] != v[i]){
                var1 = min(i, var1);
                var2 = max(var2, i);
            }
        }

        for(ll i = 0; i < var1; i++){
            if(s[i] != s[var2])
                    ok1 = true;
        }

        for(ll i = var2; i < n; i++){
            if(s[i] != s[var1])
                    ok2 = true;
        }

        if(s[var1] != s[var2] or ok1 or ok2)
            cout << "1" << "\n";        
        else
            cout << "2" << "\n";
}



        


int main()
{
    FASTIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
     solve();
    }
}