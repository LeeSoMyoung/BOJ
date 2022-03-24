

// BOJ 2230 수 고르기
// 문제 링크: https://www.acmicpc.net/problem/2230

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;

int solution(vi& arr, int n, int m) {
	int ret = (int)2e9+1;
	int front = 0, rear = 0;
	int diff;

	while (rear < n && front < n) {
		diff = arr[rear] - arr[front];

		if (diff < m) {
			++rear;
		}
		else {
			ret = min(ret, diff);
			++front;
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vi arr(n);
	forn(i, n) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cout << solution(arr, n, m) << '\n';

	return 0;
}
