#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
char arr[22][22];
bool visited[22][22][22][22];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int start_ay, start_ax, start_by, start_bx;

bool range_over(int a, int b) {
	if ((a < 1) || (b < 1) || (a > N) || (b > M)) {
		return true;
	}
	return false;
}

int bfs(int ay, int ax, int by, int bx) {
	queue<pair<pair<pair<int, int>, pair<int, int> >, int > > q;
	q.push(make_pair(make_pair(make_pair(ay, ax), make_pair(by, bx)), 0));

	while (!q.empty()) {
		int now_ay = q.front().first.first.first;
		int now_ax = q.front().first.first.second;
		int now_by = q.front().first.second.first;
		int now_bx = q.front().first.second.second;
		int now_count = q.front().second;
		visited[now_ay][now_ax][now_by][now_bx] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_ay = now_ay + moveY[i];
			int next_ax = now_ax + moveX[i];
			int next_by = now_by + moveY[i];
			int next_bx = now_bx + moveX[i];
			if ((arr[next_ay][next_ax] == '#') && (arr[next_by][next_bx] == '#')) {
				continue;
			}
			if ((range_over(now_ay, now_ax)) && (range_over(now_by, now_bx))) {
				continue;
			}
			if (((range_over(now_ay, now_ax)) && (!range_over(now_by, now_bx))) || ((!range_over(now_ay, now_ax)) && (range_over(now_by, now_bx)))) {
				if (now_count > 10) {
					return -1;
				}
				else {
					return now_count;
				}
			}

			if (arr[next_ay][next_ax] == '#') {
				next_ay -= moveY[i];
				next_ax -= moveX[i];
			}
			else if (arr[next_by][next_bx] == '#') {
				next_by -= moveY[i];
				next_bx -= moveX[i];
			}
			if (!visited[next_ay][next_ax][next_by][next_bx]) {
				q.push(make_pair(make_pair(make_pair(next_ay, next_ax), make_pair(next_by, next_bx)), now_count + 1));
			}
		}
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int coin_count = 0;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1];
			if ((arr[i][j] == 'o') && (coin_count == 0)) {
				arr[i][j] = 'A';
				coin_count++;
				start_ay = i;
				start_ax = j;
			}
			if ((arr[i][j] == 'o') && (coin_count == 1)) {
				arr[i][j] = 'B';
				coin_count++;
				start_by = i;
				start_bx = j;
			}
		}
	}
	cout << bfs(start_ay, start_ax, start_by, start_bx) << "\n";

	getchar();
	getchar();
	return 0;
}