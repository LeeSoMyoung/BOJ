
// BOJ 1351 무한수열 C++17
// 데이터구조(DS)- map, 재귀함수, 다이나믹 프로그래밍(DP)

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
using namespace std;
typedef long long int ll;
map<ll, ll> dp;

ll n, p, q;
ll dfs(ll now) {
	return (dp.count(now)>0 ? dp[now] : dp[now] = dfs(now / p) + dfs(now / q));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> p >> q;
	dp[0] = 1LL;
	cout << dfs(n) << '\n';
	return 0;
}
