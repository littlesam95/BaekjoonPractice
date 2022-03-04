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
int Cost[MAX][MAX][MAX]; // Cost[A][B][C] = A���� B����, C ������ ���������� ���ļ� �̵��� �ִ� �Ÿ�

/*
	�̽��� 2^C��� �̻� ���ø� �� �� == �ݵ�� C - 1�� ������ ���� ���ؼ��� �̵� ������.(������� �������� ���X)
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
	// C�� �����ؼ� i, j�� �� ��쿡 ���� �߰������� ��� ����
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