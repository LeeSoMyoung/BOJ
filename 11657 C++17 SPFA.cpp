
// BOJ 11657 타임머신 C++17 : SPFA 알고리즘(벨만포드 개선 알고리즘)

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

vi SPFA(int n, v& g,bool* flag) {
	vi dist(n + 1, inf),inQ(n+1,0),cycle(n+1,0);
	queue<int>q;
	int now;
	inQ[1] = 1; dist[1] = 0; ++cycle[1];
	q.push(1);
	while (!q.empty()) {
		now = q.front(); q.pop();
		inQ[now] = 0;
		for (pii next : g[now]) {
			if (dist[next.first] > dist[now] + next.second) {
				dist[next.first] = dist[now] + next.second;
				if (*flag) break;
				if (!inQ[next.first]) {
					++cycle[next.first];
					if (cycle[next.first] >= n) *flag=true;
					q.push(next.first);
					inQ[next.first] = 1;
				}
			}
		}
	}
	return dist;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b, c;
	bool cycle = false;
	v g;
	cin >> n>>m;
	g.resize(n + 1);
	while(m--) {
		cin >> a >> b >> c;
		g[a].eb(pii(b, c));
	}
	vi dist = SPFA(n, g, &cycle);
	if (cycle) return cout << -1, 0;
	cycle = false;
	rep(i,2,n+1)
		if (dist[i] >= 0) {
			cycle = true;
			break;
		}
	if (!cycle) return cout << -1, 0;
	rep(i, 2, n + 1) cout << (dist[i] == inf ? -1 : dist[i]) << '\n';
	return 0;
}
