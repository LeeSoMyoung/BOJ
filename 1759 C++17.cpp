
// 문제 링크: https://www.acmicpc.net/problem/1759

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 16
using namespace std;
typedef vector<char> vc;

map<char, int>m;
bool visited[MAX];
void go(int cur,int cnt1, int cnt2,int l,int c,vc& arr,string str) {
	if (cnt1 + cnt2 == l) {
		if (cnt1 >= 1 && cnt2 >= 2)
			cout << str << '\n';
		return;
	}
	rep(i,cur,c) {
		if (visited[i]) continue;
		visited[i] = true;
		bool flag = m.count(arr[i]);
		go(i+1,cnt1 + flag, cnt2 + 1 - flag, l, c, arr, str + arr[i]);
		visited[i] = false;
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int l, c;
	cin >> l >> c;
	vc arr(c);
	m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
	forn(i, c) cin >> arr[i];
	sort(arr.begin(), arr.end());
	go(0,0, 0, l, c, arr, "");
	return 0;
}
