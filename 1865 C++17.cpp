
// BOJ 1865 웜홀 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define inf (int)1e9
#define eb emplace_back
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vpii> v;

int main(void) {
	int tc, n, m, w, s, e, t;
	bool cycle;
	cin >> tc;
	while (tc--) {
		v g;
		cin >> n >> m >> w;
		cycle = false;
		vi dist(n + 1, inf); g.resize(n + 1);
		while (m--) {
			cin >> s >> e >> t;
			g[s].eb(pii(e, t));
			g[e].eb(pii(s, t));
		}
		while (w--) {
			cin >> s >> e >> t;
			g[s].eb(pii(e, -t));
		}
		dist[1] = 0;
		rep(i,1,n+1) rep(j,1,n+1)
			for(pii nxt:g[j])
				if (dist[nxt.first] > dist[j] + nxt.second) {
					if (i == n) cycle = true;
					dist[nxt.first] = dist[j] + nxt.second;
				}
		cout << (cycle ? "YES" : "NO") << '\n';
	}
	return 0;
}
