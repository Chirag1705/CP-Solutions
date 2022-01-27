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

// explaination -> https://www.youtube.com/watch?v=gW50l2ZtMhY

void solve(){
        string s;
        cin >> s;

        ll index = 0;

        for(ll i = 0; i < s.size()-1; i++){
            ll x = s[i] - '0';
            ll y = s[i+1] - '0';

            if(x + y > 9){
                index = i;
            }
        }

        string ans = "";

        for(ll i = 0; i < index; i++){
            ans += s[i];
        }

        ll x = s[index] - '0', y = s[index + 1] - '0';

        ans += to_string(x+y);
// or ans += s[index] - '0' + s[index + 1] - '0';
        for(ll i = index+2; i < s.size(); i++){
            ans += s[i];
        }

        cout << ans << "\n";
}

/* Another Method

#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int i=0;
		for( i=s.size()-1;i>0;i--)
		{
			if(s[i]-'0'+s[i-1]-'0'>=10)
			{s[i]=s[i]-'0'+s[i-1]-10;
			s[i-1]='1';
			break;
			}
			
		}
		if(i==0)
			{
			s[1]+=s[0]-'0';
			s=s.substr(1);
		    }
			
		cout<<s<<endl;
	}
} */

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
