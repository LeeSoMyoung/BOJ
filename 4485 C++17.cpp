
// BOJ 4485 녹색 옷 입은 애가 젤다지?

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
struct dot{
	int y, x,cost;
	dot (int y,int x, int cost): y(y), x(x),cost(cost){}
	bool operator<(dot dif) const {
		return cost > dif.cost;
	}
};

int dijkstra(int n, vvi& g) {
	vvi visited(n, vi(n, 0));
	int y, x, cost, yy, xx, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
	priority_queue<dot>pq;
	pq.push(dot(0,0,g[0][0]));
	while (!pq.empty()) {
		y = pq.top().y; x = pq.top().x; cost = pq.top().cost;
		pq.pop();
		visited[y][x] = 1;
		if (y == n - 1 && x == n - 1) return cost;
		forn(i, 4) {
			yy = y + dy[i], xx = x + dx[i];
			if (yy < 0 || xx < 0 || yy >= n || xx >= n || visited[yy][xx]) continue;
			pq.push(dot(yy, xx, cost + g[yy][xx]));
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	for (int tc = 1; cin >> n && n; ++tc) {
		vvi g(n, vi(n));
		forn(i, n) forn(j, n) cin >> g[i][j];
		cout << "Problem " << tc << ": " << dijkstra(n, g) << '\n';
	}
	return 0;
}
