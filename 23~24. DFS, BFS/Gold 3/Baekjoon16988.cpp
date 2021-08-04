#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x;
};

int N, M;
int arr[21][21];
bool visited[21][21];
bool select_zero[401];
vector<pair<int, int> > enemy, zero, candi_zero;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void init() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			visited[i][j] = false;
		}
	}
}

void init2() {
	for (int i = 0; i < 401; i++) {
		select_zero[i] = false;
	}
}

int bfs(int y, int x) {
	int count = 1;
	bool flag = true;
	queue<Info> q;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if ((arr[next_y][next_x] == 2) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x });
					count++;
				}
				else if (arr[next_y][next_x] == 0) {
					flag = false;
				}
			}
		}
	};

	if (flag) {
		return count;
	}
	return 0;
}

int calc() {
	init();
	int count = 0;
	for (int i = 0; i < enemy.size(); i++) {
		if (!visited[enemy[i].first][enemy[i].second]) {
			int num = bfs(enemy[i].first, enemy[i].second);
			count += num;
		}
	}
	return count;
}

void put_stone(int idx, int depth) {
	if (depth == 2) {
		int big = calc();
		answer = max(answer, big);
		return;
	}

	for (int i = idx; i < zero.size(); i++) {
		if (!select_zero[i]) {
			select_zero[i] = true;
			arr[zero[i].first][zero[i].second] = 1;
			put_stone(i, depth + 1);
			select_zero[i] = false;
			arr[zero[i].first][zero[i].second] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				candi_zero.push_back(make_pair(i, j));
			}
			if (arr[i][j] == 2) {
				enemy.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < candi_zero.size(); i++) {
		for (int k = 0; k < 4; k++) {
			int next_y = candi_zero[i].first + moveY[k];
			int next_x = candi_zero[i].second + moveX[k];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if (arr[next_y][next_x] == 2) {
					zero.push_back(make_pair(candi_zero[i].first, candi_zero[i].second));
					break;
				}
			}
		}
	}
	init2();
	put_stone(0, 0);
	cout << answer << "\n";
	
	getchar();
	getchar();
	return 0;
}