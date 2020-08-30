
// BOJ C++17 쉬운 계단수 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 110
using namespace std;
typedef long long int ll;

ll dp[MAX][10];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, plus, minus;
	ll ans = 0LL, MOD = (ll)1e9;
	cin >> n;
	forn(i, 10) dp[0][i] = dp[1][i] = 1LL; // dp[i][j] => 길이가 i이고 시작하는 수가 j인 계단
	rep(i, 2, n + 1) {
		forn(j,10) {
			plus = j + 1; minus = j - 1;
			if (plus >= 0 && plus <= 9) dp[i][j] += dp[i - 1][plus];
			if (minus >= 0 && minus <= 9) dp[i][j] += dp[i - 1][minus];
			dp[i][j] %= MOD;
		}
	}
	rep(i, 1, 10) ans = (ans + dp[n][i]) % MOD;
	cout << ans % MOD << '\n';
	return 0;
}
