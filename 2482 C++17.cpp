
// BOJ 2484 색상환
// tag: Dynamic Programming

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MOD ((ll)1e9+3)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vvll dp(n + 1, vll(n + 1, 0LL));
	rep(i, 2, n + 1) {
		dp[i][0] = 1LL;
		dp[i][1] = i * 1LL;
		rep(j, 2, n+1)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	}
	cout << (k<=(n>>1)?dp[n][k]:0LL) << '\n';
	return 0;
}
