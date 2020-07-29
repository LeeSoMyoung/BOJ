
// BOJ 6497 전력난 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vpii;
typedef vector<bool> vb;

int prim(int n, vpii&g) {
	int ret = 0, now, cost;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	vb visited(n, false);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		now = pq.top().second; cost = pq.top().first;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		ret += cost;
		for (pii nxt : g[now]) pq.push(pii(nxt.second, nxt.first));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b, c, sum;
	while (cin >> n >> m&&n&&m) {
		vpii g;
		g.resize(n);
		sum = 0;
		while (m--) {
			cin >> a >> b >> c;
			g[a].eb(pii(b, c));
			g[b].eb(pii(a, c));
			sum += c;
		}
		cout << sum - prim(n, g) << '\n';
	}
	return 0;
}
