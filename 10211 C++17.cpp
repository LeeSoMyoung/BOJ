
// 문제 링크 : https://www.acmicpc.net/problem/10211

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n,maxx;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n),dp(n);
		forn(i, n) cin >> arr[i];
		dp[0] = arr[0];
		rep(i, 1, n) dp[i] = max(0, dp[i - 1]) + arr[i];
		maxx = (int)-1e9;
		forn(i, n) maxx = max(maxx, dp[i]);
		cout << maxx << '\n';
	}
	return 0;
}
