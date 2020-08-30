
// BOJ 1260 DFS와 BFS C++17

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MAX 1010
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool visited[MAX];
void bfs(int start, vvi& g) {
	queue<int> q;
	int now;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		now = q.front(); q.pop();
		cout << now << ' ';
		for(int next:g[now])
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
	}
	return;
}
void dfs(int now, vvi& g) {
	cout << now << ' ';
	for(int next:g[now])
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, g);
		}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, v,a,b;
	vvi g;
	cin >> n >> m >> v;
	g.resize(n + 1);
	while (m--) {
		cin >> a >> b;
		g[a].eb(b); g[b].eb(a);
	}
	rep(i, 1, n + 1) sort(all(g[i]));
	visited[v] = true;
	dfs(v, g);
	cout << '\n';
	fill(visited, visited + MAX, false);
	bfs(v, g);
	return 0;
}
