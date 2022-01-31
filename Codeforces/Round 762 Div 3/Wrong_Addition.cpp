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
        string s1, s2;
        cin >> s1 >> s2;

        string ans = "";
        bool ok = true;

        ll s1_poin = s1.size()-1;
        ll s2_poin = s2.size()-1;

        while(s1_poin >= 0 and s2_poin >= 0){
                if((s2[s2_poin] - '0') >= (s1[s1_poin] - '0')){
                    ans += to_string((s2[s2_poin] - '0') - (s1[s1_poin] - '0'));
                    s1_poin--;
                    s2_poin--;
                }
                else{
                    if(s2_poin == 0){
                        ok = false;
                        break;
                    }

                    s2_poin--;
                    ll var = (s2[s2_poin] - '0')*10 + (s2[s2_poin+1] - '0');
                    var -= (s1[s1_poin] - '0');

                    if(var > 9 or var < 0){
                        ok = false; 
                        break;
                    }

                    ans += to_string(var);

                    s1_poin--;
                    s2_poin--;
                }
        }

        if(ok == false or s1_poin >= 0){
                cout << "-1" << "\n";
                return;
        }

            while(s2_poin >= 0){
                ans += s2[s2_poin];
                s2_poin--;
            }

            reverse(ans.begin(), ans.end());

            ll i = 0;
            while(i < ans.size()){
                    if(ans[i] != '0')
                        break;
                    i++;
            }

            ans = ans.substr(i);
            cout << ans << "\n";
            
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
