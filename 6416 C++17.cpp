
// BOJ 6416 C++17 트리인가?

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int u, v, cnt;
	bool flag;
	for (int tc = 1; cin >> u >> v && u >= 0 && v >= 0; ++tc) {
		flag = true;
		cnt = 0;
		set<int>s;
		map<int, int> m, out, in;
		if (u || v) {
			s.insert(u);
			m.insert({ v,u });
			in.insert({ v,1 });
			out.insert({ u,1 });
			while (u&&v) {
				cin >> u >> v;
				if (!u && !v) break;
				if (m.count(v) == 1 || (m.count(u) == 1 && m[u] == v)) flag = false;
				++out[u];
				++in[v];
				m.insert({ v,u });
				s.insert(u);
			}
		}
		for (int now:s)
			if (!m.count(now)&&!in[now]&&out[now]) ++cnt;
		cout << "Case " << tc << " is " << (flag &&cnt==1||m.empty()? "" : "not ") << "a tree." << '\n';
	}
	return 0;
}
