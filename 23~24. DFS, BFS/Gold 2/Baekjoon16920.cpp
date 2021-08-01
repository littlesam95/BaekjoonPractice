#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, P;
int arr[1001][1001];
int castle[10];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int player = 1;
int answer[10];
queue<pair<int, int> > q[10];

bool all_castle() {
	bool flag = true;
	for (int i = 1; i <= P; i++) {
		if (!q[i].empty()) {
			flag = false;
			break;
		}
	}
	return flag;
}

void bfs() {
	while (1) {
		for (int turn = 1; turn <= P; turn++) {
			int dist = castle[turn];
			while ((!q[turn].empty()) && (dist--)) {
				int qsize = q[turn].size();
				for (int i = 0; i < qsize; i++) {
					int now_y = q[turn].front().first;
					int now_x = q[turn].front().second;
					q[turn].pop();

					for (int i = 0; i < 4; i++) {
						int next_y = now_y + moveY[i];
						int next_x = now_x + moveX[i];
						if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
							if (arr[next_y][next_x] == 0) {
								arr[next_y][next_x] = turn;
								q[turn].push(make_pair(next_y, next_x));
								answer[turn]++;
							}
						}
					}
				}
			};
		}
		if (all_castle()) {
			break;
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) {
		int num;
		cin >> num;
		castle[i] = num;
	}
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if ((tmp[j] >= 48) && (tmp[j] <= 57)) {
				arr[i][j] = tmp[j] - '0';
				q[arr[i][j]].push(make_pair(i, j));
				answer[arr[i][j]]++;
			}
			else if (tmp[j] == '.') {
				arr[i][j] = 0;
			}
			else if (tmp[j] == '#') {
				arr[i][j] = -1;
			}
		}
	}
	bfs();
	for (int i = 1; i <= P; i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}