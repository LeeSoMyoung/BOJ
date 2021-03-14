
// 15652.cpp N과 M(4)
// 문제 링크 : https://www.acmicpc.net/problem/15652

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 10
using namespace std;

int val[MAX];
void go(int cnt,int n, int k,int prev) {
	if (cnt == k) {
		forn(i, k) cout << val[i] << ' ';
		cout << '\n';
		return;
	}
	rep(i,prev,n+1) {
		val[cnt] = i;
		go(cnt + 1, n, k,i);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	go(0,n, k,1);
	return 0;
}
