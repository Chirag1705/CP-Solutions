// if we want to check the number of divisors of all numbers from 1 to n

// O(n*sqrt(n)) method, taking too much time with lots of waste iterations
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll div_func(ll n){
        ll cnt = 0;

    for(ll i = 1; i * i <= n; i++){
        if(n%i==0){
            cnt++;

        if(i!=n/i)
            cnt++;
        }
    }

    return cnt;
}

int main(){
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++){
        cout << div_func(i) << "\n";
    }
    return 0;
}

// less than O(nlog(n)) method, multiplicative approach, only one waste iteration, efficient than previous

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll n;
    cin >> n;

    vector<ll>arr(n+1);

    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j+=i){
            arr[j]++;
        }
    }

    for(ll i = 1; i <= n; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}

// Sieve of Eratosthenes -> Even more faster method to find the prime numbers between 1 to n

#include<bits/stdc++.h>
using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll>prime(n+1, 1);

    prime[0] = 1;

    for(ll i = 2; i <= n; i++){

        if(!prime[i])
            continue;

        for(ll j = 2*i; j <= n; j += i)
                prime[j] = 0;
    } 
    return 0;
}

// Even more fast -> almost linear -> O(log(log(n)))

#include<bits/stdc++.h>
using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll>prime(n+1, 1);

    prime[0] = 1;

    for(ll i = 2; i <= n; i++){

        if(!prime[i])
            continue;

// because no. lesser than i*i must be covered with numbers <= (i-1) for sure
        for(ll j = i*i; j <= n; j += i)
                prime[j] = 0;
    } 
    return 0;
}

