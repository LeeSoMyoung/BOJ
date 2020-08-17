
// BOJ 1717 집합의 표현 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;

int find(int cur, vi&parent) {
	return parent[cur] == cur ? cur : parent[cur] = find(parent[cur], parent);
}
bool isUnion(int x, int y, vi& parent) {
	x = find(x, parent), y = find(y, parent);
	return x == y;
}
void merge(int x, int y, vi& parent) {
	y = find(y, parent), x = find(x, parent);
	if (x == y) return;
	parent[y] = x;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, cmd, a, b;
	cin >> n >> m;
	vi parent(n+1);
	forn(i, n + 1) parent[i] = i;
	while (m--) {
		cin >> cmd >> a >> b;
		if (!cmd) merge(a, b, parent);
		else cout << (isUnion(a, b, parent) ? "YES" : "NO") << '\n';
	}
	return 0;
}
