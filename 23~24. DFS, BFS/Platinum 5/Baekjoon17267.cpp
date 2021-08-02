#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x, can_L, can_R;
};

int N, M, L, R;
int arr[1001][1001];
int can_move[1001][1001];
bool visited[1001][1001];
int moveY[4] = { -1,1,0,0 };
int moveX[4] = { 0,0,-1,1 };
vector<Info> vec;
int answer = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int idx) {
	queue<Info> q;
	q.push({ vec[idx].y,vec[idx].x,vec[idx].can_L,vec[idx].can_R });
	visited[vec[idx].y][vec[idx].x] = true;

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_can_L = q.front().can_L;
		int now_can_R = q.front().can_R;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next_y = now_y;
			int next_x = now_x;
			while (1) {
				next_y += moveY[i];
				next_x += moveX[i];
				if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
					if (arr[next_y][next_x] == 0) {
						if (!visited[next_y][next_x]) {
							visited[next_y][next_x] = true;
							q.push({ next_y,next_x,now_can_L,now_can_R });
						}
					}
					else if (arr[next_y][next_x] == 1) {
						break;
					}
				}
				else {
					break;
				}
			};
		}
		if (now_can_L > 0) {
			int next_y = now_y + moveY[2];
			int next_x = now_x + moveX[2];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if ((arr[next_y][next_x] == 0) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x,now_can_L - 1,now_can_R });
				}
			}
		}
		if (now_can_R > 0) {
			int next_y = now_y + moveY[3];
			int next_x = now_x + moveX[3];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if ((arr[next_y][next_x] == 0) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x,now_can_L,now_can_R - 1 });
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> L >> R;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			arr[i][j] = S[j] - '0';
			if (arr[i][j] == 2) {
				vec.push_back({ i,j,L,R });
				arr[i][j] = 0;
			}
		}
	}
	init();
	bfs(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				answer++;
			}
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}