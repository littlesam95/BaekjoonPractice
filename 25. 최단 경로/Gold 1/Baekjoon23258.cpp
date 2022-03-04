#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 301
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
int Cost[MAX][MAX][MAX]; // Cost[A][B][C] = A에서 B까지, C 이하의 경유지만을 거쳐서 이동한 최단 거리

/*
	이슬을 2^C방울 이상 마시면 안 됨 == 반드시 C - 1번 이하의 집을 통해서만 이동 가능함.(출발지와 도착지는 상관X)
*/

void Input() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Cost[i][j][0];
			if (i == j) {
				continue;
			}
			if (Cost[i][j][0] == 0) {
				Cost[i][j][0] = INF;
			}
		}
	}
}

void Settings() {
	// C를 경유해서 i, j로 간 경우에 대한 중간과정을 모두 저장
	for (int C = 1; C <= N; C++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				Cost[i][j][C] = min(Cost[i][j][C - 1], Cost[i][C][C - 1] + Cost[C][j][C - 1]);
			}
		}
	}
}

void Query() {
	for (int i = 0; i < Q; i++) {
		int C, S, E;
		cin >> C >> S >> E;
		if (Cost[S][E][C - 1] == INF) {
			cout << -1 << "\n";
		}
		else {
			cout << Cost[S][E][C - 1] << "\n";
		}
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Query();

	getchar();
	getchar();
	return 0;
}