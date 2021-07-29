#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
int arr[51][51];
int tmp[51][51];
bool checked[51][51];
vector<pair<int, int> > viruses;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = INT_MAX;

int bfs() {
	int virus_time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = -1;
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < viruses.size(); i++) {
		q.push(make_pair(viruses[i].first, viruses[i].second));
		tmp[viruses[i].first][viruses[i].second] = 0;
	}

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N)) {
				if ((arr[next_y][next_x] != 1) && (tmp[next_y][next_x] == -1)) {
					tmp[next_y][next_x] = tmp[now_y][now_x] + 1;
					virus_time = max(virus_time, tmp[next_y][next_x]);
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	};

	bool all_virus = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((tmp[i][j] == -1) && (arr[i][j] != 1)) {
				all_virus = false;
			}
		}
	}
	if (!all_virus) {
		virus_time = INT_MAX;
	}

	return virus_time;
}

void make_virus(int y, int x, int depth) {
	if (depth == M) {
		answer = min(answer, bfs());
		return;
	}

	for (int i = y; i < N; i++) {
		for (int j = x; j < N; j++) {
			if ((arr[i][j] == 2) && (!checked[i][j])) {
				checked[i][j] = true;
				viruses.push_back(make_pair(i, j));
				make_virus(i, j, depth + 1);
				checked[i][j] = false;
				viruses.pop_back();
			}
			x = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	make_virus(0, 0, 0);
	if (answer < INT_MAX) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}