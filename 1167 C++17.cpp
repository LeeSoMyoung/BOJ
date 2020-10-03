
// BOJ 1167 트리의 지름 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define MAX 100100
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

bool visited[MAX];
vvpii g;
int maxx = -1, start, to, ans;
void dfs(int now, int cnt) {
	int next;
	if (cnt > maxx) {
		maxx = cnt;
		start = now;
	}
	for (pii nxt : g[now]) {
		next = nxt.first;
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, cnt + nxt.second);
		}
	}
	return;
}
void dfs2(int now,int cnt) {
	if (now == to) {
		ans = cnt;
		return;
	}
	int next;
	for (pii nxt : g[now]) {
		next = nxt.first;
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, cnt + nxt.second);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, node, e, dist, from;
	cin >> v;
	g.resize(v + 1);
	while(v--) {
		cin >> node;
		while (cin >> e && e + 1) {
			cin >> dist;
			g[node].eb(pii(e, dist));
		}
	}
	visited[1] = true;
	dfs(1, 0);
	from = start;
	fill(visited, visited + MAX, false);
	maxx = -1;
	visited[start] = true;
	dfs(from, 0);
	cout << maxx << '\n';
	return 0;
}
