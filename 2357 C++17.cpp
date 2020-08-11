
// BOJ 2357 최솟값과 최댓값 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> v;

void update(int index, pii val, int h, v& tree) {
	index += h - 1;
	tree[index] = val;
	while (index /= 2)
		tree[index] = pii(min(tree[index * 2].first, tree[index * 2 + 1].first), max(tree[index * 2].second, tree[index * 2 + 1].second));
	return;
}
pii query(int start, int end, int index, int left, int right, v& tree) {
	if (start <= left && right <= end) return tree[index];
	else if (right < start || end < left) return pii((int)1e9,0);
	int mid = (left + right) >> 1;
	pii val1 = query(start, end, index * 2, left, mid, tree), val2 = query(start, end, index * 2 + 1, mid + 1, right, tree);
	return pii(min(val1.first, val2.first), max(val1.second, val2.second));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, val, a, b, h=1;
	pii print;
	cin >> n >> m;
	while (n > h) h <<= 1;
	v tree(h * 2);
	forn(i, n) {
		cin >> val;
		update(i + 1, pii(val, val), h, tree);
	}
	while (m--) {
		cin >> a >> b;
		print = query(min(a, b), max(a, b), 1, 1, h, tree);
		cout << print.first << ' ' << print.second << '\n';
	}
	return 0;
}
