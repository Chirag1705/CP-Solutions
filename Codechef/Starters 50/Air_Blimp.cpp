#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while(t--){
	    ll n, x, y;
	    cin >> n >> x >> y;
	    
	    vector<ll>arr(n);
	    
	    for(ll i = 0; i < n; i++)
	    cin >> arr[i];
	    
	    ll temp1 = INT_MIN;
	    
	    for(ll i = 0; i < n; i++){
	        if(arr[i]%y == 0)
	        temp1 = max(temp1, arr[i]/y);
	        else
	        temp1 = max(temp1, arr[i]/y + 1);
	    }
	    
	    if(x >= y){
	        ll blimp = 0;
	        
	        for(ll i = n-1; i >= 0; i--){
	            arr[i] -= blimp*y;
	            
	            if(arr[i] > 0){
	                if(arr[i]%x == 0)
	                    blimp += arr[i]/x;
	                else
	                    blimp += arr[i]/x + 1;
	            }
	        }
	        
	        temp1 = min(temp1, blimp);
	        
	        cout << temp1 << "\n";
	    }
	    else
	    cout << temp1 << "\n";
	}
	return 0;
}
