
// BOJ 1068 트리 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define eb emplace_back
#define MAX 55
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool visited[MAX];
void bfs(int root, int del, int* ans, vvi&tree) {
	queue<int>q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (!tree[now].size())++*ans;
		for (int next : tree[now]) {
			if (visited[next]) continue;
			else if (next == del) {
				if (tree[now].size()==1)++*ans;
				continue;
			}
			visited[next] = true;
			q.push(next);
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, del,root,ans=0,parent;
	cin >> n;
	vvi tree; tree.resize(n);
	forn(i, n) {
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		tree[parent].eb(i);
	}
	cin >> del;
	if (del == root) return cout << 0, 0;
	visited[root] = true;
	bfs(root, del, &ans, tree);
	cout << ans << '\n';
	return 0;
}
