
// BOJ 정수 제곱근
// 문제 링크: https://www.acmicpc.net/problem/2417

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef unsigned long long int ull;

ull solution(ull n) {
	ull front = 1, rear = sqrt(n)+50, mid;
	ull val;

	while (front < rear) {
		mid = (front + rear) >> 1;
		val = mid * mid;

		if (val >= n) {
			rear = mid;
		}
		else {
			front = mid + 1;
		}
	}
	return rear;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ull n;
	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}
