#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
        // ll n;
        // cin >> n;

        string s;
        cin >> s;

        auto ch = min_element(s.begin(), s.end());

        cout << *ch << " ";
        
        s.erase(ch);
    
        cout << s << "\n";

        

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

 ll t;
 cin >> t;

 while(t--){
     solve();
 }

return 0;
}