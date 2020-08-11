
// BOJ 10423 전기가 부족해 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;

struct edge {
	int a, b, dist;
	bool operator<(const edge&cmp) const {
		return cmp.dist < dist;
	}
};
int find(int cur, vi&parent) {
	return parent[cur]==-1?-1:(parent[cur] == cur ? cur : parent[cur] = find(parent[cur], parent));
}
bool isUnion(int x, int y, vi& parent) {
	x = find(x, parent), y = find(y, parent);
	return x == y;
}
void merge(int x, int y, vi& parent) {
	y = find(y, parent), x = find(x, parent);
	if (x == y) return;
	else if (x == -1) parent[y] = x;
	else if (y == -1) parent[x] = y;
	else parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k,u,v,dist,ans=0,val;
	priority_queue<edge>pq;
	edge top;
	cin >> n >> m >> k;
	vi parent(n+1);
	rep(i, 1, n + 1) parent[i] = i;
	while (k--) {
		cin >> val;
		parent[val] = -1;
	}
	while (m--) {
		cin >> u >> v >> dist;
		pq.push({ u,v,dist });
	}
	while (!pq.empty()) {
		top = pq.top(); pq.pop();
		if (!isUnion(top.a, top.b, parent)) {
			ans += top.dist;
			merge(top.a, top.b, parent);
		}
	}
	cout << ans << '\n';
	return 0;
}
