#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
char arr[11][11];
int a, b, c, d;
bool visited[11][11][11][11] = { false, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;
string answer_order;

struct Bead {
	int red_y, red_x, blue_y, blue_x, moving;
	string order;
};

void bfs(int a, int b, int c, int d, int e) {
	queue<Bead> q;
	visited[a][b][c][d] = true;
	q.push({ a, b, c ,d, e, "" });

	while (!q.empty()) {
		int now_red_y = q.front().red_y;
		int now_red_x = q.front().red_x;
		int now_blue_y = q.front().blue_y;
		int now_blue_x = q.front().blue_x;
		int now_moving = q.front().moving;
		string now_order = q.front().order;
		q.pop();

		if (now_moving >= 10) {
			answer = -1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_red_y = now_red_y, next_red_x = now_red_x, next_blue_y = now_blue_y, next_blue_x = now_blue_x;
			int red_moving = 0, blue_moving = 0;
			int next_moving = now_moving + 1;
			string next_order = now_order;
			if (i == 0) {
				next_order += "U";
			}
			else if (i == 1) {
				next_order += "L";
			}
			else if (i == 2) {
				next_order += "D";
			}
			else if (i == 3) {
				next_order += "R";
			}
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
			if (arr[next_blue_y][next_blue_x] == 'O') {
				continue;
			}
			if (arr[next_red_y][next_red_x] == 'O') {
				answer = next_moving;
				answer_order = next_order;
				return;
			}
			if ((next_red_y == next_blue_y) && (next_red_x == next_blue_x)) {
				if (red_moving > blue_moving) {
					next_red_y -= moveY[i];
					next_red_x -= moveX[i];
				}
				else {
					next_blue_y -= moveY[i];
					next_blue_x -= moveX[i];
				}
			}
			if (!visited[next_red_y][next_red_x][next_blue_y][next_blue_x]) {
				visited[next_red_y][next_red_x][next_blue_y][next_blue_x] = true;
				q.push({ next_red_y, next_red_x, next_blue_y, next_blue_x, next_moving, next_order });
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
	bfs(a, b, c, d, 0);
	cout << answer << "\n";
	if (answer != -1) {
		cout << answer_order << "\n";
	}

	getchar();
	getchar();
	return 0;
}