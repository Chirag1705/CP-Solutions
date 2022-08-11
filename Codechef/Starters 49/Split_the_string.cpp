#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while(t--){
	    ll n, k;
	    cin >> n >> k;
	    
	    string s;
	    cin >> s;
	    
	    ll c1 = 0, c0 = 0;
	    
	    for(ll i = 0; i < n; i++){
	        if(s[i] == '1')
	        c1++;
	        else
	        c0++;
	    }
	    
	    n -= 2 * min(c1, c0);
	    
	    if(n%k)
	        cout << n/k + 1 << "\n";
	    else
	        cout << n/k << "\n";
	}
	return 0;
}
