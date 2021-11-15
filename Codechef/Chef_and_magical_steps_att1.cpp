#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
    bool prime[MAXN + 2];
    int tot_primes_till[MAXN + 2];

void sieve(){
    
    int n = MAXN;
    fill(begin(prime), end(prime), true);
    prime[0] = prime[1] = false;

    for(int i = 2; i <= n; i++){
        tot_primes_till[i] = tot_primes_till[i-1];

        if(!prime[i])
            continue;

        tot_primes_till[i]++;

        for(int j = 2*i; j <= n; j += i){
            prime[j] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

    sieve();

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;
        int ans = y - x - (tot_primes_till[y] - tot_primes_till[x + 1]);

        cout << ans << "\n";
    }
    return 0;
}