
// BOJ DNA 비밀번호
// 문제 링크: https://www.acmicpc.net/problem/12891

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef vector<int> vi;

int check(vi& cnt, vi& sum) {
	forn(i, 4) {
		if (cnt[i] > sum[i]) {
			return 0;
		}
	}
	return 1;
}

int solve(vi& cnt, int s, int p, string str) {
	int ret = 0;
	int front = 0, rear = 0;
	bool flag = true;
	vi sum(4, 0);
	map<char, int> m;

	m['A'] = 0;
	m['C'] = 1;
	m['G'] = 2;
	m['T'] = 3;

	while (front <= rear) {
		if (rear == front + p - 1) {
			if (flag) {
				flag = false;
				if (m.count(str[rear])) {
					++sum[m[str[rear]]];
				}
			}
			ret += check(cnt, sum);
			if (m.count(str[front])) {
				--sum[m[str[front]]];
			}

			++front;
			++rear;
			if (rear >= s) {
				break;
			}
			if (m.count(str[front])) {
				++sum[m[str[front]]];
			}
			if (m.count(str[rear])) {
				++sum[m[str[rear]]];
			}
		}
		else {
			if (m.count(str[rear])) {
				++sum[m[str[rear]]];
			}
			++rear;
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int s, p;
	string str;
	vi cnt(4);

	cin >> s >> p >> str;
	forn(i, 4) {
		cin >> cnt[i];
	}

	cout << solve(cnt, s, p, str) << '\n';
	return 0;
}
