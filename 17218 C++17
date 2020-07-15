
// BOJ 17218 비밀번호 만들기 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,N) rep(i,0,N)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	int len1, len2,idx1,idx2;
	stack<int>st;
	cin >> str1 >> str2;
	str1 = '.' + str1; str2 = '.' + str2;
	len1 = str1.size(); len2 = str2.size();
	vvi lcs(len1, vi(len2, 0));
	forn(i, len1) forn(j, len2) {
		if (!i || !j) continue;
		if (str1[i] == str2[j])
			lcs[i][j] = lcs[i - 1][j - 1] + 1;
		else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
	}
	idx1 = len1 - 1, idx2 = len2 - 1;
	while (lcs[idx1][idx2]) {
		if (lcs[idx1][idx2] == lcs[idx1][idx2 - 1]) --idx2;
		else if (lcs[idx1][idx2] == lcs[idx1 - 1][idx2]) --idx1;
		else if (lcs[idx1][idx2] -1== lcs[idx1 - 1][idx2 - 1]) {
			st.push(idx1);
			--idx1; --idx2;
		}
	}
	while (!st.empty()) {
		cout << str1[st.top()];
		st.pop();
	}
	return 0;
}
