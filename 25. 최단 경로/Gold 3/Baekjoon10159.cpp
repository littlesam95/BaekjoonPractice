#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N, M;
int dist[401][401];
int answer = 0;

void init() {
	for (int i = 0; i < 401; i++) {
		for (int j = 0; j < 401; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = MAX;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = -1;
		dist[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((dist[i][k] == 1) && (dist[k][j] == 1)) {
					dist[i][j] = 1;
				}
				else if ((dist[i][k] == -1) && (dist[k][j] == -1)) {
					dist[i][j] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int comp_cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			if ((dist[i][j] == MAX) || (dist[j][i] == MAX)) {
				comp_cnt++;
			}
		}
		cout << comp_cnt << "\n";
	}

	getchar();
	getchar();
	return 0;
}