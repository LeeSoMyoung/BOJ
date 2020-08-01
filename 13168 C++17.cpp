
// BOJ 13168 내일로의 여행 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define inf (int)1e9
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, r, m, k, cost, sum1 = 0, sum2 = 0, u, v;
	string type, start, destination, city;
	map<string, int>mm;
	cin >> n >> r;
	vvi g(n, vi(n, inf));
	vvi g2(n, vi(n, inf));
	forn(i, n) {
		cin >> city;
		mm.insert({ city,i });
		g[i][i] = g2[i][i] = 0;
	}
	cin >> m;
	vs arr(m);
	forn(i, m) cin >> arr[i];
	cin >> k;
	while (k--) {
		cin >> type >> start >> destination >> cost;
		u = mm[start], v = mm[destination];
		g[u][v] = min(g[u][v], cost);
		g[v][u] = g[u][v];
		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
			g2[u][v] = g2[v][u] = 0;
		}
		else if (type == "S-Train" || type == "V-Train") {
			g2[u][v] = min(g2[u][v], cost / 2);
			g2[v][u] = g2[u][v];
		}
		else {
			g2[u][v] = min(g2[u][v], cost);
			g2[v][u] = g2[u][v];
		}
	}
	forn(p, n) forn(i, n) forn(j, n) {
		if (g[i][j] > g[i][p] + g[p][j])
			g[i][j] = g[i][p] + g[p][j];
		if (g2[i][j] > g2[i][p] + g2[p][j])
			g2[i][j] = g2[i][p] + g2[p][j];
	}
	forn(i, m - 1) {
		u = mm[arr[i]], v = mm[arr[i + 1]];
		sum1 += (g[u][v] == inf ? 0 : g[u][v]);
		sum2 += (g2[u][v] == inf ? 0 : g2[u][v]);
	}
	cout << (sum1 > sum2 + r ? "Yes" : "No") << '\n';
	return 0;
}
