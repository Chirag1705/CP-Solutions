// modular arithmatic

// binpow already done
// mod add, mul, sub done

// mod div imp ->
// Fermat's Little Thoerm

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 
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

int main(){
    ll a, b, m;

    cin >> a >> b >> m;

    ll res1 = (a/b)%m;
    a = a%m;

    ll inv_b = pw(b, m-2, m);
    // inverse of b = b^m-2%m, only for prime m

    ll res2 = a*inv_b % m;

    // compare res1 and res2
    return 0;
}


