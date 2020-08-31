
// BOJ 1963 소수 경로 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
#define MAX 10005
using namespace std;

bool isNotPrime[MAX], visited[MAX];
int bfs(int from, int to) {
	int ret = 0, now, size, val;
	string cur, next;
	queue<string>q;
	q.push(to_string(from));
	visited[from] = true;
	while (!q.empty()) {
		size = q.size();
		while (size--) {
			cur = q.front(); q.pop();
			now = stoi(cur);
			if (now == to) return ret;
			forn(i, 4) forn(j, 10) {
				next = cur;
				if (next[i] == j+'0') continue;
				next[i] = j+'0';
				val = stoi(next);
				if (val < 1000 || isNotPrime[val]||visited[val]) continue;
				q.push(next);
				visited[val] = true;
			}
		}
		++ret;
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, from, to, val;
	cin >> tc;
	isNotPrime[1] = true;
	rep(i, 2, MAX)
		if (!isNotPrime[i])
			for (int j = i * 2; j < MAX; j += i)
				isNotPrime[j] = true;
	while (tc--) {
		cin >> from >> to;
		fill(visited, visited + MAX, false);
		val = bfs(from, to);
		cout << (val == -1 ? "Impossible" : to_string(val)) << '\n';
	}
	return 0;
}
