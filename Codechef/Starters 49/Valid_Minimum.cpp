#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while(t--){
	    ll a, b, c;
	    cin >> a >> b >> c;
	            
	  if(a == b and b == c and c == a){
	      cout << "YES" << "\n";
	      continue;
	  }  
	  
	    if(a == b){
	        if(c > a)
	        cout << "YES" << "\n";
	        else
	        cout << "NO" << "\n";
	        
	    }
	    else if(b == c){
	        if(a > b)
	        cout << "YES" << "\n";
	        else
	        cout << "NO" << "\n";
	    }
	    else if(c == a){
	        if(b > a)
	        cout << "YES" << "\n";
	        else
	        cout << "NO" << "\n";
	    }
	    else
	        cout << "NO" << "\n";
	}
	return 0;
}
