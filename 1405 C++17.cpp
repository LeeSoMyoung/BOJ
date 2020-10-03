
// BOJ 1405 미친로봇 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 30
using namespace std;
typedef vector<double> vd;

bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
double dfs(int y, int x, int n, vd& pp) {
	if (!n) return 1.0;
	double ret = 0.0;
	int yy, xx;
	visited[y][x] = true;
	forn(i, 4) {
		yy = y + dy[i];
		xx = x + dx[i];
		if (visited[yy][xx]) continue;
		ret += pp[i] * dfs(yy, xx, n - 1, pp);
	}
	visited[y][x] = false;
	return ret;

}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	double p;
	vd possibility(4);
	cin >> n;
	forn(i, 4) {
		cin >> p;
		possibility[i] = p / 100.0;
	}
	cout.precision(9);
	cout << dfs(MAX/2,MAX/2,n,possibility) << '\n';
	return 0;
}
