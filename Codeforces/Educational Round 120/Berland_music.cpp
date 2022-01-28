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

        vt<ll>arr(n), q(n);
        vt<vt<ll>>v(n);


        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        string s;
        cin >> s;

        ll var = 1;



        for(ll i = 0; i < n; i++){
            if(s[i]=='1')
                v[i] = {arr[i], 1, i};
            else
                v[i] = {arr[i], 0, i};

        }

        sort(v.begin(), v.end());

        for(ll i = 0; i < n; i++){

            ll status = v[i][1];
            ll idx = v[i][2];

            if(status==0){
                q[idx] = var;
                var++;
            }
        } 

        for(ll i = 0; i < n; i++){
            ll status = v[i][1];
            ll idx = v[i][2];

            if(status == 1){
                q[idx] = var;
                var++;
            }
        }

        for(auto x : q){
                cout << x << " ";
        }

        cout << "\n"; 

        /*  cin >> n;
        vector<pll> liked, unliked;
        vll p(n + 1, 0);
        fo(i, 1, n)
        {
            cin >> p[i];
        }
        cin >> s;
        fo(i, 0, n - 1)
        {
            if (s[i] == '1')
            {
                liked.pb({p[i + 1], i + 1});
            }
            else
            {
                unliked.pb({p[i + 1], i + 1});
            }
        }
        sort(allr(liked));
        sort(allr(unliked));
        ll curr = n;
        vll ansvec(n + 1);
        for (auto x : liked)
        {
            ansvec[x.second] = curr;
            curr--;
        }
        for (auto x : unliked)
        {
            ansvec[x.second] = curr;
            curr--;
        }
        fo(i, 1, n)cout << ansvec[i] << " ";
        cout << "\n"; */
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

