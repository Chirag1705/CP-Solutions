#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	
	ll t;
	cin >> t;
	
	while(t--){
	    ll n;
	    cin >> n;
	    
	    vector<ll>arr(n);
	    
	    ll sum = 0;
	    
	    for(ll i = 0; i < n; i++){
	        cin >> arr[i];
	        sum += arr[i];
	    }
	    
	    ll x = 1, cnt = 0;
	    
	    while(x <= sum){
	        sum -= x;
	        cnt++;
	        x++;
	    }
	    
	    cout << cnt << "\n";
	}
	
	return 0;
}
