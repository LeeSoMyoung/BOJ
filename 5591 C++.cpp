
// 문제 링크: https://www.acmicpc.net/problem/5591
// BOJ 5591 C++

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;

int solve(vi& arr, int n, int k) {
	int front = 0, rear = 0, sum = 0;
	int ret = 0;

	while (rear <= n) {
		if (rear == front + k) {
			ret = max(ret, sum);
			
			sum -= arr[front++];
			if (rear < n) {
				sum += arr[rear++];
			}
			else {
				++rear;
			}
		}
		else {
			sum += arr[rear++];
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vi arr(n);

	forn(i, n) {
		cin >> arr[i];
	}

	cout << solve(arr, n, k) << '\n';

	return 0;
}
