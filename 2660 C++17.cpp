
// BOJ 2660 C++17 회장뽑기

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define MAX 55
#define inf (int)1e9
#define eb emplace_back
using namespace std;
typedef vector<int>vi;
typedef vector<vi> vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,score=inf,u,v;
	vi ans;
	cin >> n;
	vvi g(n, vi(n, inf));
	vi arr(n);
	forn(i, n) g[i][i] = 0;
	while(1) {
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		g[u - 1][v - 1] = g[v - 1][u - 1] = 1;
	}
	forn(k, n) forn(i, n) forn(j, n)
		if (g[i][j] > g[i][k] + g[k][j])
			g[i][j] = g[i][k] + g[k][j];
	forn(i, n) {
		int maxx = -1;
		forn(j, n)
			if (i != j && g[i][j] > maxx) maxx = g[i][j];
		arr[i] = maxx;
		score = min(maxx, score);
	}
	forn(i, n) if (arr[i] == score) ans.eb(i + 1);
	cout << score << ' ' << ans.size() << '\n';
	for (int print : ans) cout << print << ' ';
	return 0;
}
