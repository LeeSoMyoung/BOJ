
// BOJ 17472 다리 만들기2 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 15
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

bool visited[MAX][MAX];
struct edge {
	int a,b,dist;
	bool operator<(const edge&cmp) const {
		return cmp.dist < dist;
	}
};
int find(int cur, vi& parent) {
	return parent[cur] == cur ? cur : parent[cur] = find(parent[cur], parent);
}
bool isUnion(int a, int b, vi&parent) {
	a = find(a, parent), b = find(b, parent);
	return a == b;
}
void merge(int a, int b, vi& parent) {
	a = find(a, parent), b = find(b, parent);
	if (a == b) return;
	parent[b] = a;
	return;
}
void bfs(int n,int m, int y, int x, vvi&g,int* cnt) {
	int yy, xx, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 },nowy,nowx;
	queue<pii>q;
	visited[y][x] = true;
	q.push(pii(y, x));
	while (!q.empty()) {
		nowy = q.front().first, nowx = q.front().second; q.pop();
		g[nowy][nowx] = *cnt;
		forn(i, 4) {
			yy = nowy + dy[i], xx = nowx + dx[i];
			if (yy < 0 || xx < 0 || yy >= n || xx >= m || visited[yy][xx] || !g[yy][xx]) continue;
			visited[yy][xx] = true;
			q.push(pii(yy, xx));
		}
	}
	++*cnt;
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, cnt=1,ans=0, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 },yy,xx,maxx;
	priority_queue<edge> pq;
	edge top;
	cin >> n >> m;
    maxx=max(n,m);
	vvi g(n, vi(m));
	forn(i, n) forn(j, m) cin >> g[i][j];
	forn(i, n) forn(j, m)
		if (!visited[i][j] && g[i][j])
			bfs(n, m, i, j, g, &cnt);
	vi parent(cnt);
	rep(i, 1, cnt) parent[i] = i;
	forn(i,n) forn(j,m)
		if (g[i][j]) {
				forn(k, 4) {
					rep(size,1,maxx){
					yy = i + dy[k] * size, xx = j + dx[k] * size;
					if (yy < 0 || xx < 0 || yy >= n || xx >= m || !g[yy][xx]) continue;
					if (g[yy][xx] == g[i][j]) break;
					pq.push({ g[i][j],g[yy][xx],size-1 });
					break;
				}
			}
		}
	while (!pq.empty()) {
		top = pq.top(); pq.pop();
		if (!isUnion(top.a, top.b, parent)&&top.dist>1) {
			ans += top.dist;
			merge(top.a, top.b, parent);
		}
	}
	rep(i, 2, cnt)
		if (find(1, parent) != find(i, parent))
			return cout << -1, 0;
	cout << ans << '\n';
	return 0;
}
