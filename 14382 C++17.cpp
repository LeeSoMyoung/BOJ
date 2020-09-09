
// BOJ 14382 숫자 세는 양(Large) C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

bool visited[10];
bool chk(void) {
	forn(i, 10)
		if (!visited[i])
			return false;
	return true;
}
void check(int n) {
	string str = to_string(n);
	int len = str.size();
	forn(i, len)
		visited[str[i] - '0'] = true;
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, val, cnt, ans;
	cin >> n;
	forn(i, n) {
		cin >> val;
		cout << "Case #" << (i + 1) << ": ";
		if (!val) {
			cout << "INSOMNIA" << '\n';
			continue;
		}
		fill(visited, visited + 10, false);
		cnt = 1LL;
		while (!chk()) {
			ans = val * cnt;
			check(ans);
			++cnt;
		}
		cout << ans << '\n';
	}
	return 0;
}
