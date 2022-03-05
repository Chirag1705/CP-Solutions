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
        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        ll cnt = 0;

        for(ll i = 0; i < n; i++){
            if(s[i] == '*')
                cnt++;
        }
       
        if(cnt == 1){
            cout << "1" << "\n";
            return;
        }

        cnt = 1;

        ll ind1 = 0, ind2 = 0;

        for(ll i = 0; i < n; i++){
            if(s[i]=='*'){
                ind1 = i;
                break;
            }
        }

        for(ll i = n-1; i >= 0; i--){
            if(s[i]=='*'){
                ind2 = i;
                break;
            }
        }

       
       ll i = ind1;
        
       while(i < ind2){
           if(s[i+k] != '*' and (i+k) < ind2){
               for(ll j = i+k-1; j >= i+1; j--){
                   if(s[j]=='*'){
                       cnt++;
                       i = j;
                       break;
                   }
               }
           }
           else if(s[i+k] == '*' and (i+k) < ind2){
               i = (i+k);
               cnt++;
           }
           else{
               break;
           }
       }

        cout << cnt+1 << "\n";

/* Simple Approach ->

int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int pos1=s.find('*');
		int pos2=s.rfind('*');
		int ans=1;
	    while(pos1!=pos2)
	    {
	    	pos1+=k;
	    	while(pos1>=n||s[pos1]!='*')pos1--;
	    	ans++;
		}
		cout<<ans<<endl;

        */

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