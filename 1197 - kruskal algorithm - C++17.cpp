
// 문제 링크 : https://www.acmicpc.net/problem/1197

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define MAX 10010
using namespace std;

typedef struct node {
	int a,b, w;
	bool operator<(node cmp)const {
		return w > cmp.w;
	}
	node(int a,int b, int w) {
		this->a = a;
		this->b = b;
		this->w = w;
	}
}node;

typedef long long int ll;
typedef vector<node> vn;
typedef vector<vn>vvn;

int parent[MAX];

int find(int cur) {
	if (parent[cur] == cur) return cur;
	return parent[cur] = find(parent[cur]);
}
void myUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[a] = b;
	return;
}
priority_queue<node>pq;
bool isUnion(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b;
}
bool visited[MAX];
ll kruskal(void) {
	ll ret = 0LL;
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		if (!isUnion(cur.a, cur.b)) {
			myUnion(cur.a, cur.b);
			ret += cur.w*1LL;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e,a,b,c;
	cin >> v >> e;
	forn(i, v + 1) parent[i] = i;
	while (e--) {
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}
	cout << kruskal() << '\n';
	return 0;
}
