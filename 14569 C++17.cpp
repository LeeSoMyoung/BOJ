
// 문제 링크: https://www.acmicpc.net/problem/14569

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;;

ll bitmasking(vi& arr) {
	ll ret = 0;
	int size = arr.size();
	forn(i, size)
		ret += (1LL << (arr[i]-1));
	return ret;
}
bool chk(ll student, ll lecture) {
	return (student & lecture) == lecture;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k;
	cin >> n;
	vi lectures(n);
	forn(j,n) {
		cin >> k;
		vi arr(k);
		forn(i, k) cin >> arr[i];
		lectures[j] = bitmasking(arr);
	}
	cin >> m;
	vi ans(m, 0);
	forn(i,m) {
		cin >> k;
		vi arr(k);
		forn(j, k) cin >> arr[j];
		ll bm = bitmasking(arr);
		forn(j, n)
			ans[i] += chk(bm,lectures[j]);
	}
	for (ll print : ans) cout << print << '\n';
	return 0;
}
