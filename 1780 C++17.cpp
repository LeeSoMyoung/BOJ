
// BOJ 1780 종이의 개수 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void go(int y, int x, int size, int* plus, int* zero, int* minus,vvi&g) {
	if (!size) return;
	bool flag = true;
	int num = g[y][x];
	rep(i, y, y + size) {
		rep(j,x,x+size)
			if (num != g[i][j]) {
				flag = false;
				break;
			}
		if (!flag) break;
	}
	if (flag) {
		if (num == 1) ++*plus;
		else if (num == -1) ++*minus;
		else ++*zero;
	}
	else {
		size /= 3;
		forn(i, 3) forn(j, 3)
			go(y + i * size, x + j * size, size, plus, zero, minus, g);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, plus = 0, zero = 0, minus = 0;
	cin >> n;
	vvi g(n, vi(n));
	forn(i, n) forn(j, n) cin >> g[i][j];
	go(0, 0, n, &plus, &zero, &minus,g);
	cout << minus << '\n' << zero << '\n' << plus << '\n';
	return 0;
}
