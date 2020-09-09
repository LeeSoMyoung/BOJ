
// BOJ 5635 생일 C++17

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define all(x) x.begin(),x.end()
using namespace std;
struct s{
	string name;
	int day, month, year;
	bool operator<(const s&cmp) const {
		if (year == cmp.year) {
			if (month == cmp.month)
				return day > cmp.day;
			return month > cmp.month;
		}
		return year > cmp.year;
	}
};

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<s> arr(n);
	forn(i, n) cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
	sort(all(arr));
	cout << arr[0].name << '\n' << arr[n - 1].name;
	return 0;
}
