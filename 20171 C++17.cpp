
// 문제 링크 : https://www.acmicpc.net/problem/20171

#define _CRT_SECURE_NO_wARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define pb push_back
#define MAX 100100
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
bool visited[MAX], arr[MAX];
int ans = 0;
int dfs(int cur) {
	int ret = 0, cnt = 0, next, cost, val, size;
	size = g[cur].size();
	forn(i, size) {
		next = g[cur][i];
		if (visited[next]) continue;
		visited[next] = true;
		val = dfs(next);
		if (val < 0) continue;
		++cnt;
		ret += val;
	}
	if (arr[cur]) {
		ans += ret + 1;
		return 0;
	}
	++ret;
	if (cnt > 1) {
		ans += ret;
		return 0;
	}
	else if (cnt == 1) {
		return ret;
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, u, v, w, input;
	cin >> n >> k;
	g.resize(n + 1);
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(v);
		g[v].pb(u);
	}
	while (k--) {
		cin >> input;
		arr[input] = true;
	}
    if(n==k) return cout<<n<<'\n',0;
	visited[input] = true;
	dfs(input);
	cout << ans << '\n';
	return 0;
}
