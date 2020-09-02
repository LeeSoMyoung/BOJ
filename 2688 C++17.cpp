
// BOJ 2688 줄어들지 않아 C++17
// 다이나믹 프로그래밍(DP)

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define MAX 68
using namespace std;
typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, n;
	ll dp[MAX][10]; //dp[i][j] = 길이가 i이고 j이하로 시작하는 수들 중 줄어주는 수의 개수
	cin >> tc;
	forn(i, 10) dp[0][i] = 1LL;
	rep(i, 1, 65) forn(j, 10)
		dp[i][j] = dp[i - 1][j] + (j ? dp[i][j - 1] : 0);
	while (tc--) {
		cin >> n;
		cout << dp[n][9] << '\n';
	}
	return 0;
}
