#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while(t--){
	    ll x, y;
	    cin >> x >> y;
	    
	    ll half = x/2;
	    ll other_half = x - half;
	    bool f = 0;
	    
	    for(ll i = 1; i <= sqrt(y); i++){
	        if(y%i == 0){
	            if((i > other_half and y/i > other_half) or (i < half and y/i < half)){
	                cout << half << " " << other_half << "\n";
	                cout << i << " " << y/i << "\n";
	                f = 1;
	                break;
	            }
	        }
	    }
	    
	    if(!f)
	    cout << "-1" << "\n";
	}
	return 0;
}
