
// BOJ 10974 모든 순열 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 10
using namespace std;

int ans[10];
bool visited[10];
void go(int now, int n) {
	if (n == now) {
		forn(i, n) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	rep(i, 1, n + 1) if (!visited[i]) {
		visited[i] = true;
		ans[now] = i;
		go(now + 1, n);
		visited[i] = false;
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	go(0, n);
	return 0;
}
