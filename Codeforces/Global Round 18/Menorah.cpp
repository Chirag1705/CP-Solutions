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

ll func1(string a, string b){
    ll cnt10 = 0, cnt01 = 0;

    for(ll i = 0; i < a.size(); i++){
        if(a[i]!=b[i]){
            if(a[i]=='0')
                cnt01++;
            else
                cnt10++;
        }
    }

    if(cnt10 == cnt01)
        return (cnt01 + cnt10);
    else
        return -1;
}

bool func2(string& x, string& y, char b){
    ll index = -1;

    for(ll i = 0; i < x.size(); i++){
        if(x[i] == '1' and y[i] == b){
            index = i;
            break;
        }
    }

    if(index == -1)
        return 0;
    
    for(ll i = 0; i < x.size(); i++){
        if(i == index)
            continue;
        if(x[i]=='1')
            x[i] = '0';
        else
            x[i] = '1';
    }
    return 1;
}


void solve(){
        ll n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

       ll ans = 1e10;

       ll a1 = func1(s1, s2);

       if(a1 != -1){
           ans = min(ans, a1);
       }

       if(func2(s1, s2, '1')){
           ll a2 = func1(s1, s2);
           if(a2 != -1)
            ans = min(ans, 1 + a2);
       }

       if(func2(s1, s2, '0')){
           ll a3 = func1(s1, s2);
           if(a3 != -1)
            ans = min(ans, 1 + a3);
       }

        if(!(ans == 1e10))
       cout << ans << "\n";
       else
        cout << "-1" << "\n";
}
        /* Another Method ->

        int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	map<int, int> f1, f2;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			f1[a[i] - '0']++;
		else
			f2[a[i] - '0']++;
	}
	int ans = INF;
	if (f1[1] == f1[0])
		ans = min(ans, f1[1] + f1[0]);
	if (f2[1] == f2[0] + 1)
		ans = min(ans, f2[1] + f2[0]);
	
	if (ans == INF)
		ans = -1;
	print(ans); */


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