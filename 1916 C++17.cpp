
// BOJ 1916 최소비용 구하기 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define eb emplace_back
#define inf (int)1e9
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vpii> v;

int dijkstra(int start, int end, int n, v& g) {
	vi dist(n + 1, inf);
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	int now, cost, nc, next;
	dist[start] = 0;
	pq.push(pii(0, start));
	while (!pq.empty()) {
		now = pq.top().second; cost = pq.top().first;
		pq.pop();
		if (dist[now] < cost) continue;
		for (pii nxt : g[now]) {
			next = nxt.first; nc = nxt.second;
			if (dist[next] > cost + nc) {
				dist[next] = cost + nc;
				pq.push(pii(dist[next], next));
			}
		}
	}
	return dist[end];
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m,a,b,cost,start,end;
	v g;
	cin >> n >> m;
	g.resize(n + 1);
	while (m--) {
		cin >> a >> b >> cost;
		g[a].eb(pii(b, cost));
	}
	cin >> start >> end;
	cout << dijkstra(start, end, n, g) << '\n';
	return 0;
}
