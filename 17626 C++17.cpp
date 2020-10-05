
// BOJ 17626 Four Squares / Dynamic Programming

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 50010
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,dp[MAX],prev=1,chk=1;
	fill(dp, dp + MAX, -1);
	cin >> n;
	for (int i = 1; i*i <= n; ++i)
		dp[i*i] = 1;
	rep(i, 2, n + 1) {
		if (dp[i] == 1) {
			prev = i;
			chk = sqrt(prev);
			continue;
		}
		dp[i] = dp[prev] + dp[i - prev];
		rep(j, 1, chk)
			dp[i] = min(dp[i], dp[j*j] + dp[i - j * j]);
	}
	cout << dp[n] << '\n';
	return 0;
}
