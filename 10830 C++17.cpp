
// 문제 링크 : https://www.acmicpc.net/problem/10830

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define mod (ll)1e3
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vvi square(vvi matrix, int n) {
	vvi ret(n, vi(n,0));
	forn(i, n) forn(j, n) forn(k, n)
			ret[i][j] = (ret[i][j] + matrix[i][k] * matrix[k][j]) % mod;
	return ret;
}
vvi multiply(vvi a, vvi b, int n) {
	vvi ret(n, vi(n,0));
	forn(i, n) forn(j, n) forn(k, n)
		ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
	return ret;
}
vvi ans(vvi& matrix, int n, ll num) {
	if (!num) {
		vvi ret(n, vi(n, 0));
		forn(i, n) ret[i][i] = 1;
		return ret;
	}
	vvi half = ans(matrix, n, num / 2);
	if (num & 1) return multiply(matrix, square(half, n),n);
	else return square(half, n);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
    ll b;
	cin >> n >> b;
	vvi matrix(n, vi(n)), answer;
	forn(i, n) forn(j, n) cin >> matrix[i][j];
	answer = ans(matrix, n, b);
	for (vi v : answer) {
		for (ll print : v)
			cout << print << ' ';
		cout << '\n';
	}
	return 0;
}
