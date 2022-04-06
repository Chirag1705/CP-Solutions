#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    string s;
	    cin >> s;
	    
	    int cnt1 = 0;
	    for(int i = 0; i < s.size(); i++){
	        if(s[i] == '1')
	            cnt1++;
	    }
	    
	    if(cnt1 == 0){
	        cout << "0" << "\n";
	        continue;
	    }
	    
	    bool ok = 0;
	    
	    for(int i = 0; i < s.size()-1; i++){
	        if(s[i] == s[i+1] and s[i] == '1'){
	            ok = 1;
	            break;
	    }
	   }
	   
	   if(ok)
	    cout << "2" << "\n";
	    else
	    cout << "1" << "\n";
	}
	return 0;
}
