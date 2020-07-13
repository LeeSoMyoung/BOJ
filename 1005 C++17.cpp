
// BOJ 1005 ACM Craft C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define eb emplace_back
using namespace std;
typedef vector<int>vi;
typedef vector<vi> vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc,n,k,u,v,w;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		vi ans(n), time(n),in(n,0);
		vvi g; g.resize(n);
		forn(i, n) {
			cin >> time[i];
			ans[i] = time[i];
		}
		while (k--) {
			cin >> u >> v;
			g[u - 1].eb(v-1);
			++in[v - 1];
		}
		queue<int>q;
		forn(i, n) if (!in[i]) q.push(i);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int next : g[now]) {
				--in[next];
				if (!in[next]) q.push(next);
				ans[next] = max(ans[next], ans[now] + time[next]);
			}
		}
		cin >> w;
		cout << ans[w - 1] << '\n';
	}
	return 0;
}
