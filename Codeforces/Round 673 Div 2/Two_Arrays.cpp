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
        ll n, T;
        cin >> n >> T;

        vt<ll>arr(n), v(n);
        map<ll, ll>m;

        ll cnt = 0;

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            m[arr[i]]++;

            if(arr[i] == T/2 and T%2==0)
                cnt++;
        }

        for(ll i = 0; i < n; i++){
            if(arr[i] == T/2 and T%2==0){
                if(m[arr[i]] > cnt/2){
                    cout << "0" << " ";
                }
                else
                    cout << "1" << " ";

                m[arr[i]]--;
                continue;
            }

            if(m[T - arr[i]] and m[arr[i]]){
                m[T - arr[i]] = 0;
            }

            if(m[arr[i]] == 0){
                cout << "1" << " ";
            }
            else{
                cout << "0" << " ";
            }
        }

        cout << "\n";
}

/* Another Approach ->
 int n, tar;
	cin >> n >> tar;
	int curMid = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		int r;
		if (tar % 2 == 0 && x == tar/2)
			r = (curMid++) % 2;
		else if (2*x < tar)
			r = 0;  
		else
			r = 1;
		cout << r << " \n"[i==n-1];
	}  */
/* --> Let us partition the array into three sets X, Y, Z such that 
X contains all numbers less than T/2, 
Y contains all numbers equal to T/2 
and Z contains all numbers greater than T/2. 
It is clear that f(X)=f(Z)=0. 
Now, since each pair in Y makes a sum of T, 
the best solution is to distribute all numbers in Y equally among X and Z. */

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
