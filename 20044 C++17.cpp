
// BOJ 20044 Project Teams C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans=(int)1e9;
	cin>>n;
	vi arr(2*n);
	forn(i,2*n) cin>>arr[i];
	sort(all(arr));
	forn(i,n) ans=min(arr[i]+arr[2*n-1-i],ans);
	cout<<ans<<'\n';
	return 0;
}
