
// BOJ 15809 전국시대 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;

struct edge {
	int a, b, dist;
	bool operator<(const edge&cmp) const {
		return cmp.dist < dist;
	}
};
int find(int cur, vi&parent) {
	return parent[cur] == cur ? cur : parent[cur] = find(parent[cur], parent);
}
bool isUnion(int x, int y, vi& parent) {
	x = find(x, parent), y = find(y, parent);
	return x == y;
}
void merge(int x, int y, vi& parent,vi& power) {
	y = find(y, parent), x = find(x, parent);
	if (x == y) return;
	parent[max(x,y)] = min(x,y);
	power[x] = power[y] = power[x] + power[y];
}
void war(int x, int y, vi&parent, vi&power) {
	int xx = find(x, parent), yy = find(y, parent);
	if (xx != yy) {
		if (power[xx] == power[yy]) {
			power[xx] = power[yy] = 0;
			parent[xx] = parent[yy] = 0;
		}
		else if (power[xx] > power[yy]) {
			power[xx] -= power[yy];
			power[yy] = 0;
			parent[yy] = xx;
		}
		else {
			power[yy] -= power[xx];
			power[xx] = 0;
			parent[xx] = yy;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m,o,p,q;
	priority_queue<edge>pq;
	cin >> n >> m;
	vi parent(n + 1),power(n+1),ans;
	rep(i, 1, n + 1) {
		cin >> power[i];
		parent[i] = i;
	}
	while (m--) {
		cin >> o >> p >> q;
		if (o == 1) merge(p, q, parent, power);
		else war(p, q, parent, power);
	}
	rep(i, 1, n + 1)
		if (parent[i] == i)
			ans.eb(power[i]);
	sort(all(ans));
	cout << ans.size() << '\n';
	for (int print : ans) cout << print << ' ';
	return 0;
}
