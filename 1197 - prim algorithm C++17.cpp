
// 문제 링크 : https://www.acmicpc.net/source/29878446

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define MAX 10010
using namespace std;

typedef struct node {
	int adj, w;
	bool operator<(node cmp)const {
		return w > cmp.w;
	}
	node(int adj, int w) {
		this->adj = adj;
		this->w = w;
	}
}node;

typedef long long int ll;
typedef vector<node> vn;
typedef vector<vn>vvn;

bool visited[MAX];
ll prim(vvn &g) {
	ll ret = 0LL;
	priority_queue<node>pq;
	pq.push(node(1, 0));
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		if (visited[cur.adj]) continue;
		visited[cur.adj] = true;
		ret += cur.w;
		for (node next : g[cur.adj])
			if (!visited[next.adj])
				pq.push(next);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e,a,b,c;
	vvn g;
	cin >> v >> e;
	g.resize(v + 1);
	while (e--) {
		cin >> a >> b >> c;
		g[a].eb(node(b,c));
		g[b].eb(node(a,c));
	}
	cout << prim(g) << '\n';
	return 0;
}
