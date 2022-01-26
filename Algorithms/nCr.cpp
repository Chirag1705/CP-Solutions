
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


