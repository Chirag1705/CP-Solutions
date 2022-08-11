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
	    map<ll, ll>m;
	    ll mx = INT_MIN, mxele = 0, temp = INT_MIN;
	    
	    for(ll i = 0; i < n; i++){
    	    cin >> arr[i];
    	    m[arr[i]]++;
    	    
    	    if(m[arr[i]] > mx){
    	        mxele = arr[i];
    	        mx = m[arr[i]];
    	    }
    	    
    	    temp = max(temp, arr[i]);
	    }
	   
	    m[temp+1] = m[mxele] - m[mxele]/2;
	    m[mxele] = m[mxele]/2;
	    
	    ll ans = INT_MIN;
	    
	    for(auto i : m){
	        ans = max(ans, i.second);
	    }
	    
	    cout << ans << "\n";
	}
	return 0;
}
