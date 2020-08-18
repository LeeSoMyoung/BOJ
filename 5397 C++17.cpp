
// BOJ 5397 키로거 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

string reverse(string& str) {
	string ans = "";
	int len = str.size();
	for (int i = len - 1; i >= 0; --i)
		ans += str[i];
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int TC;
	string str;
	cin >> TC;
	while (TC--) {
		cin >> str;
		stack<char>st;
		stack<char>tmp;
		string pw = "";
		int length = str.size();
		forn(i, length) {
			if (str[i] == '-') {
				if (!st.empty()) st.pop();
			}
			else if (str[i] == '<') {
				if (!st.empty()) {
					tmp.push(st.top());
					st.pop();
				}
			}
			else if (str[i] == '>') {
				if (!tmp.empty()) {
					st.push(tmp.top());
					tmp.pop();
				}
			}
			else st.push(str[i]);
		}
		while (!tmp.empty()) {
			st.push(tmp.top());
			tmp.pop();
		}
		while (!st.empty()) {
			pw += st.top();
			st.pop();
		}
		cout << reverse(pw) << '\n';
	}
	return 0;
}
