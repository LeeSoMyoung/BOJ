
// BOJ 1944 복제로봇 C++17

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
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

bool bfs(int node, int n, int m, vvc&g, pii& start,vvpii&graph,vvi& num) {
	queue<pii>q;
	vvb visited(n + 1, vb(n + 1, false));
	vvi dist(n + 1, vi(n + 1, 0));
	int y, x, yy, xx, dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 },cnt=1;
	q.push(start);
	visited[start.first][start.second] = true;
	while (!q.empty()) {
		y = q.front().first, x = q.front().second;
		q.pop();
		forn(i, 4) {
			yy = y + dy[i], xx = x + dx[i];
			if (yy < 0 || xx < 0 || yy >= n || xx >= n || visited[yy][xx]||g[yy][xx]=='1') continue;
			visited[yy][xx] = true;
			q.push(pii(yy, xx));
			dist[yy][xx] = dist[y][x] + 1;
			if (g[yy][xx] == 'K') {
				++cnt;
				graph[node].eb(pii(num[yy][xx], dist[yy][xx]));
			}
			if (m == cnt) return false;
		}
	}
	return m != cnt;
}
int prim(int number, vvpii& graph) {
	int ret = 0, now, cost;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	vb visited(number + 1, false);
	pq.push(pii(0, 1));
	while (!pq.empty()) {
		now = pq.top().second; cost = pq.top().first;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		ret += cost;
		for (pii nxt : graph[now]) pq.push(pii(nxt.second, nxt.first));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m,number=1;
	vvpii graph;
	cin >> n >> m;
	vvc g(n, vc(n));
	vvi num(n, vi(n, 0));
	vpii key;
	++m;
	forn(i, n) forn(j, n) {
		cin >> g[i][j];
		if (g[i][j] == 'K') {
			key.eb(pii(i, j));
			num[i][j] = number++;
		}
		else if (g[i][j] == 'S') {
			key.eb(pii(i, j));
			num[i][j] = number++;
			g[i][j] = 'K';
		}
	}
	graph.resize(number+1);
	for (pii chk : key)
		if (bfs(num[chk.first][chk.second],n, m, g, chk, graph,num))
			return cout << -1, 0;
	cout << prim(number, graph) << '\n';
	return 0;
}
