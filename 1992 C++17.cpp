
// BOJ 1992 쿼드트리 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;

void go(int y, int x, int size, vvc& g) {
	if (!size) return;
	char color = g[y][x];
	bool flag = true;
	rep(i, y, y + size) {
		rep(j,x,x+size)
			if (color != g[i][j]) {
				flag = false;
				break;
			}
		if (!flag) break;
	}
	if (flag) cout << color;
	else {
		size /= 2;
		cout << '(';
		forn(i, 2) forn(j, 2)
			go(y + i * size, x + j * size, size, g);
		cout << ')';
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vvc g(n, vc(n));
	forn(i, n) forn(j, n) cin >> g[i][j];
	go(0, 0, n, g);
	return 0;
}
