
// BOJ 1149 RGB거리 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans=(int)1e9;
	cin >> n;
	vvi arr(n, vi(3)), dp(n, vi(3, 0));
	forn(i, n) forn(j, 3) cin >> arr[i][j];
	forn(i, n) dp[0][i] = arr[0][i];
	rep(i, 1, n) forn(j, 3)
		dp[i][j] = arr[i][j]+(j ? (j==1?min(dp[i-1][0],dp[i-1][2]):min(dp[i-1][0],dp[i-1][1])): min(dp[i-1][1],dp[i-1][2]));
	forn(i, 3) ans = min(ans, dp[n - 1][i]);
	cout << ans << '\n';
	return 0;
}
