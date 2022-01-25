// Counting the number of divisors in O(sqrt(n)) times
// We can check if a number is prime or not

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    ll n;
    cin >> n;

    ll cnt = 0;

    for(ll i = 1; i * i <= n; i++){
        if(n%i==0)
            cnt++;

        if(i!=n/i)
            cnt++;
    }

    cout << cnt << "\n";
    
    return 0;
}
