#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
char arr[11][11];
int a, b, c, d;
bool visited[11][11][11][11] = { false, }; // 빨간 구슬 및 파란 구슬이 특정 좌표를 각각 방문했을 때 방문했음을 표시하는 배열을 4차원으로 나타냄
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

struct Bead { // 구슬의 좌표를 저장한 구조체
	int red_y, red_x, blue_y, blue_x, moving;
};

void bfs(int a, int b, int c, int d, int e) {
	queue<Bead> q;
	visited[a][b][c][d] = true;
	q.push({ a, b, c ,d, e });

	while (!q.empty()) {
		int now_red_y = q.front().red_y;
		int now_red_x = q.front().red_x;
		int now_blue_y = q.front().blue_y;
		int now_blue_x = q.front().blue_x;
		int now_moving = q.front().moving;
		q.pop();

		if (now_moving >= 10) { // 10번까지 되는 줄 알았는데 이동 거리가 10이 넘어가면 -1을 출력하는거같음.(내가 해석을 잘못한듯)
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_red_y = now_red_y, next_red_x = now_red_x, next_blue_y = now_blue_y, next_blue_x = now_blue_x;
			int red_moving = 0, blue_moving = 0;
			int next_moving = now_moving + 1;
			// 벽 또는 구멍이 아니라면 계속 그 방향으로 이동
			while ((arr[next_red_y + moveY[i]][next_red_x + moveX[i]] != '#') && (arr[next_red_y][next_red_x] != 'O')) {
				next_red_y += moveY[i];
				next_red_x += moveX[i];
				red_moving += 1;
			};
			while ((arr[next_blue_y + moveY[i]][next_blue_x + moveX[i]] != '#') && (arr[next_blue_y][next_blue_x] != 'O')) {
				next_blue_y += moveY[i];
				next_blue_x += moveX[i];
				blue_moving += 1;
			};
			if (arr[next_blue_y][next_blue_x] == 'O') { // 파란 구슬이 구멍을 만나면 안 되므로, 파란 구슬이 구멍에 빠진 경우라면 큐에 넣지 않는다.
				continue;
			}
			if (arr[next_red_y][next_red_x] == 'O') { // 빨간 구슬이 구멍을 만났을 경우 BFS를 종료하고 이동 거리를 반환한다.
				answer = next_moving;
				return;
			}
			if ((next_red_y == next_blue_y) && (next_red_x == next_blue_x)) { //  두 구슬이 만났다면 이동한 거리가 큰 구슬이 이동하지 않는다. 최솟값을 물어봤기 때문이다.
				if (red_moving > blue_moving) {
					next_red_y -= moveY[i];
					next_red_x -= moveX[i];
				}
				else {
					next_blue_y -= moveY[i];
					next_blue_x -= moveX[i];
				}
			}
			if (!visited[next_red_y][next_red_x][next_blue_y][next_blue_x]) { // 현재 빨간 구슬 및 파란 구슬의 좌표를 각각 방문하지 않은 상태라면 방문했음을 표시하고 큐에 넣는다.
					visited[next_red_y][next_red_x][next_blue_y][next_blue_x] = true;
					q.push({ next_red_y, next_red_x, next_blue_y, next_blue_x, next_moving });
			}
		}
	};
	answer = -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp[j];
			if (arr[i][j] == 'R') {
				a = i;
				b = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				c = i;
				d = j;
				arr[i][j] = '.';
			}
		}
	}
	bfs(a, b, c, d, 0); // 빨간 구슬, 파란 구슬의 현재 위치 및 이동 거리(0)을 시작점으로 하여 BFS 시작
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}