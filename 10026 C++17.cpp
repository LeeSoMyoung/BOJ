
// BOJ 10026 적록색약 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define MAX 110
using namespace std;
typedef pair<int, int> pii;
typedef vector<char> vc;
typedef vector<vc> vvc;

bool visited[MAX][MAX];
void bfs(int Y, int X, int n, vvc& g) {
	queue<pii>q;
	int y, x, yy, xx, dx[4] = { 0,0,1,-1 }, dy[4] = {1,-1,0,0};
	char chk = g[Y][X];
	q.push(pii(Y, X));
	visited[Y][X] = true;
	while(!q.empty()) {
		y = q.front().first; x = q.front().second; q.pop();
		forn(i, 4) {
			yy = y + dy[i], xx = x + dx[i];
			if (yy < 0 || xx < 0 || yy >= n || xx >= n || visited[yy][xx]||g[yy][xx]!=chk) continue;
			q.push(pii(yy, xx));
			visited[yy][xx] = true;
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans1 = 0, ans2 = 0;
	cin >> n;
	vvc g(n, vc(n)), gg(n, vc(n));
	forn(i, n) forn(j, n) {
		cin >> g[i][j];
		gg[i][j] = (g[i][j] == 'G' ? 'R' : g[i][j]);
	}
	forn(i,n) forn(j,n)
		if (!visited[i][j]) {
			bfs(i, j, n, g);
			++ans1;
		}
	memset(visited, false, sizeof(visited));
	forn(i, n) forn(j, n)
		if (!visited[i][j]) {
			bfs(i, j, n, gg);
			++ans2;
		}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}
