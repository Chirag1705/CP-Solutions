
// Combinatorics -> P&C
// nCr
#include<iostream>
using namespace std;
#define ll long long
const ll N = 2e5+7;  // Lets suppose
const ll mod = 1e9+7;

ll pw(ll a, ll p = mod-2, ll MOD = mod){
    ll res = 1;
    while(p>0){
        if(p&1)
            res = a*res%MOD;
        a = a*a%MOD;
        p >>= 1;
    }
    return res;
}

ll fact[N], invfact[N];

void init(){
    ll p = mod;
    fact[0] = 1;
    ll i;
    for(i = 1; i < N; i++){
        fact[i] = i*fact[i-1]%p;
    }
    i--;
    invfact[i] = pw(fact[i], p-2, p);

    for(i--; i >= 0; i--){
        invfact[i] = invfact[i+1]*(i+1)%p;
    }
}

ll nCr(ll n, ll r){
    if(r > n or n < 0 or r < 0)
        return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}

int main(){
    
    return 0;
}

--------------------------------------------------------------------------------------
    
ll power(ll x, ll y, ll p)
{
	unsigned ll res = 1;
	x = x % p;

	while (y > 0)
	{

		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modInverse(ll n, ll p) {
	return power(n, p - 2, p);
}

ll nCrModPFermat(ll n, ll r, ll mod) {
	if (n < r)
		return 0;

	if (r == 0)
		return 1;

	ll fact[n + 1];

	fact[0] = 1;

	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}
