
// BOJ 2630 색종이 만들기 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;

void go(int y, int x, int size, vvc& g,int* white,int* blue) {
	if (!size) return;
	bool flag = true;
	char color = g[y][x];
	rep(i, y, y + size) {
		rep(j,x,x+size)
			if (color != g[i][j]) {
				flag = false;
				break;
			}
		if (!flag) break;
	}
	if (flag) {
		if (color-'0') ++*blue;
		else ++*white;
		return;
	}
	else {
		size /= 2;
		go(y, x, size, g, white, blue); go(y+size, x, size, g, white, blue);
		go(y, x+size, size, g, white, blue); go(y+size, x+size, size, g, white, blue);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,white=0,blue=0;
	cin >> n;
	vvc g(n, vc(n));
	forn(i, n) forn(j, n) cin >> g[i][j];
	go(0, 0, n, g, &white, &blue);
	cout << white << '\n' << blue << '\n';
	return 0;
}
