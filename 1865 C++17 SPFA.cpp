
// BOJ 1865 웜홀 C++17 : SPFA

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define inf (int)1e9
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii>v;
typedef vector<int> vi;

bool SPFA(int n, v& g) {
	vi visited(n + 1, 0), inQ(n + 1, 0),dist(n+1,inf);
	queue<int>q;
	int now;
	rep(i, 1, n + 1) {
		if (visited[i]) continue;
		vi cycle(n + 1, 0);
		dist[i] = 0;
		++cycle[i]; q.push(i); inQ[i] = 1;
		while (!q.empty()) {
			now = q.front(); q.pop();
			inQ[now] = 0;
			for (pii next : g[now]) {
				if (dist[next.first] > dist[now] + next.second) {
					dist[next.first] = dist[now] + next.second;
					if (!inQ[next.first]) {
						++cycle[next.first];
						if (cycle[next.first] >= n) return true;
						q.push(next.first);
						inQ[next.first] = 1;
					}
				}
			}
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, n, m, w, s, e, t;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		v g; g.resize(n + 1);
		while (m--) {
			cin >> s >> e >> t;
			g[s].eb(pii(e, t));
			g[e].eb(pii(s, t));
		}
		while (w--) {
			cin >> s >> e >> t;
			g[s].eb(pii(e, -t));
		}
		cout << (SPFA(n, g) ? "YES" : "NO") << '\n';
	}
	return 0;
}
