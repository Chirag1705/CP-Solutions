#include<bits/stdc++.h>
using namespace std; 
#define int long long
int n,m;
pair<string,int>a[1000001];
signed main(){
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++){
        cin>>s;
		for(int j=1;j<s.size();j+=2) s[j]='Z'-(s[j]-'A');
		a[i]={s,i+1};
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i].second<<" ";
}
