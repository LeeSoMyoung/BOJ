
// BOJ 4419 호주식 투표법 C++17 

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define MAX 1010
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi>vvi;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,cnt,num,half,minn,idx;
	bool flag = true;
	cin >> n;
	cin.ignore();
	vs str(n);
	vvi score(MAX, vi(n, 0));
	vi final_score(n, 0);
	forn(i, n) getline(cin, str[i]);
	for (cnt = 0;cin>>num; ++cnt) {
		score[cnt][0] = --num;
		rep(i, 1, n) {
			cin >> num;
			score[cnt][i] = --num;
		}
	}
	half = cnt >> 1;
	while (1) {
		forn(i, n) final_score[i] = 0;
		forn(i, cnt) {
			forn(j, n)
				if (str[score[i][j]][0]) {
					idx = j;
					break;
				}
			++final_score[score[i][idx]];
		}
		minn = (int)1e9;
		forn(i, n) {
			if (final_score[i] > half)
				return cout << str[i], 0;
			if(str[i][0])
				minn = min(minn, final_score[i]);
		}
		forn(i,n)
			if (str[i][0]&&final_score[i] != minn) {
				flag = false;
				break;
			}
		if (flag) {
			forn(i, n) if(str[i][0]) cout << str[i] << '\n';
			return 0;
		}
		forn(i, n)
			if (final_score[i] == minn)
				str[i][0] = '\0';
	}
	return 0;
}
