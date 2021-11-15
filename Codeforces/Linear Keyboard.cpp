#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
        
        string s1, s2;

        cin >> s1 >> s2;
        map<char, int>m;

        map<char, int>::iterator it ;
        map<char, int>::iterator it1 ;
        

        for(int i = 0; i < s1.size(); i++){
            m[s1[i]]++;
            m[s1[i]] = i+1;
        }

        ll ans = 0;

        for(int i=0; i < s2.size()-1; i++){
                it = m.find(s2[i]);
                it1 = m.find(s2[i+1]);

                ans += abs(it->second - it1->second);
            
        }

        cout << ans << endl;
        
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll t;

    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
