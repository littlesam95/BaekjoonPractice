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
int dist[101][101];
int route[101][101];
vector<int> vec;
int answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = MAX;
		}
	}
}

void find_route(int S, int E) {
	if (route[S][E] == 0) {
		vec.push_back(S);
		vec.push_back(E);
		return;
	}
	find_route(S, route[S][E]);
	vec.pop_back();
	find_route(route[S][E], E);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					route[i][j] = k;
				}
			}
		}
	}
	// 도시 i에서 j로 가기 위한 최소 비용 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				cout << 0 << " ";
			}
			else {
				if (dist[i][j] == MAX) {
					cout << 0 << " ";
				}
				else {
					cout << dist[i][j] << " ";
				}
			}
		}
		cout << "\n";
	}
	// 도시 i에서 j로 가기 위한 최소 비용에 포함되어 있는 도시의 개수 및 경로 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i == j) || (dist[i][j] == MAX)) {
				cout << 0 << " ";
			}
			else {
				vec.clear();
				find_route(i, j);
				cout << vec.size() << " ";
				for (int k = 0; k < vec.size(); k++) {
					cout << vec[k] << " ";
				}
			}
			cout << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}