
// BOJ 11657 C++17 타임머신

#include <stdio.h>
#include <vector>
#include <utility>
#define MAX 510
#define INF 2*1e9
using namespace std;
typedef pair<int, int> P;

int dist[MAX];
unsigned int n;
vector<vector<P>>v;
bool cycle;

void bellman_ford(int end) {
	size_t i, j;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (P check : v[j])
				if (dist[j] != INF && dist[check.first] > dist[j] + check.second) {
					if (i == n) cycle = 1;
					dist[check.first] = dist[j] + check.second;
				}
}

int main(void) {
	int m, a, b, c;
	size_t i, j;
	scanf("%u %d", &n, &m);
	v.resize(n + 1);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	bellman_ford(n);
	if (cycle) puts("-1");
	else {
		bool flag = false;
		for (i = 2; i <= n; ++i)
			if (dist[i]>=0) {
				flag = true;
				break;
			}
		if (!flag) puts("-1");
		else for (i = 2; i <= n; ++i)
			printf("%d\n", dist[i]==INF?-1:dist[i]);
	}
	return 0;
}
