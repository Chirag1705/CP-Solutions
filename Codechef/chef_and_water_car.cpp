#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
        ll n, v;
        cin >> n >> v;

        if(v==1){
            cout << n*(n-1)/2 << " " << n*(n-1)/2 << "\n";
        }

        else if(v >= n-1){
            cout << n*(n-1)/2 << " " << n-1 << "\n";
        }

        else{
            cout << n*(n-1)/2 << " " << (n-v)*(n-v+1)/2 + v-1 << "\n";
        }

        /* In this case we fill V amount of fuel at the start only, then remaining n-1-v amt of fuel for remaining n-2 distance.
        1 lit of fuel should be filled till n-v points starting from 2. So, total cost [n*(n+1)/2-1] + V excluding 1st lit or 
        1st km as we have already filled V lit, thus adding V.
        Here n is n-v+1 */

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

 int t;
 cin >> t;

 while(t--){
     solve();
 }

return 0;
}
