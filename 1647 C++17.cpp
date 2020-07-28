
// BOJ 1647 도시 분할 계획 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<bool> vb;

int prim(int n, vvpii&g) {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	int maxx = -1, ret = 0, now, cost;
	vb visited(n + 1, false);
	pq.push(pii(0, 1));
	while (!pq.empty()) {
		now = pq.top().second; cost = pq.top().first;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		maxx = max(maxx, cost);
		ret += cost;
		for (pii next : g[now]) pq.push(pii(next.second, next.first));
	}
	ret -= maxx;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m,u,v,c;
	vvpii g;
	cin >> n >> m;
	g.resize(n + 1);
	while (m--) {
		cin >> u >> v >> c;
		g[u].eb(pii(v, c));
		g[v].eb(pii(u, c));
	}
	cout << prim(n, g) << '\n';
	return 0;
}
