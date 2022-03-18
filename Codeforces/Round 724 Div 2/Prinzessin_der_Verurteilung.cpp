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
#define set_bits __builtin_popcountll


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

        string s;
        cin >> s;

        map<int, int>m;

        for(ll i = 0; i < n; i++){
            m[s[i] - 'a']++;
        }

        for(ll i = 0; i < 26; i++){
            if(m[i] == 0){
                cout << char('a' + i) << "\n";
                return;
            }
        }

        set<string>s1, s2;

        for(ll i = 0; i < n-1; i++){
                string temp;
                temp += s[i];
                temp += s[i+1];
                s1.insert(temp);
        }

        for(ll i = 0; i < 26; i++){
            for(ll j = 0; j < 26; j++){
                string temp;
                temp += char('a' + i);
                temp += char('a' + j);
                if(s1.find(temp) == s1.end()){
                    cout << temp << "\n";
                    return;
                }
            }
        }

        for(ll i = 0; i < n; i++){
                string temp;
                temp += s[i];
                temp += s[i+1];
                temp += s[i+2];
                s2.insert(temp);
        }

        for(ll i = 0; i < 26; i++){
            for(ll j = 0; j < 26; j++){
                string temp = "a";
                temp += char('a' + i);
                temp += char('a' + j);
                if(s2.find(temp) == s2.end()){
                    cout << temp << "\n";
                    return;
                }
            }
        }
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
