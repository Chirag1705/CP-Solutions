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
	    
	    ll even = 0, odd = 0;
	    
	    for(ll i = 0; i < n; i++){
	        cin >> arr[i];
	        if(arr[i]%2==0)
	            even++;
	        else
	            odd++;
	    }
	    
	    if(even == 0 or odd == 0){
	        cout << "0" << "\n";
	        continue;
	    }
	    
	    if((even%2==0 and odd%2==0) or (even%2!=0 and odd%2==0)){
	        cout << min(even, odd/2) << "\n";
	        continue;
	    }

	    if((even%2==0 and odd%2!=0) or (even%2 != 0 and odd%2 != 0)){
	        cout << even << "\n";
	        continue;
	    }
	    
	    
	}
	return 0;
}
