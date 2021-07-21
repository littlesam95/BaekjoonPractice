#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int T;
int w, h;
char arr[110][110];
bool visited[110][110];
string start_key;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int key;
int answer;

void init() {
	w = 0;
	h = 0;
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			arr[i][j] = '.';
			visited[i][j] = false;
		}
	}

	start_key = "";
	key = 0;
	answer = 0;
}

void init2() {
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y <= h + 1) && (next_x >= 0) && (next_x <= w + 1) && (!visited[next_y][next_x]) && (arr[next_y][next_x] != '*')) {
				if ((arr[next_y][next_x] >= 'a') && (arr[next_y][next_x] <= 'z')) {
					int idx = arr[next_y][next_x] - 'a';
					key |= (1 << idx);
					arr[next_y][next_x] = '.';
					while (!q.empty()) {
						q.pop();
					};
					init2();
					q.push(make_pair(0, 0));
					visited[0][0] = true;
					break;
				}
				else if ((arr[next_y][next_x] >= 'A') && (arr[next_y][next_x] <= 'Z')) {
					int idx = arr[next_y][next_x] - 'A';
					if ((key & (1 << idx))) {
						arr[next_y][next_x] = '.';
						q.push(make_pair(next_y, next_x));
					}
				}
				else if (arr[next_y][next_x] == '$') {
					answer++;
					arr[next_y][next_x] = '.';
					q.push(make_pair(next_y, next_x));
				}
				if (arr[next_y][next_x] == '.') {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}
		cin >> start_key;
		if (start_key != "0") {
			for (int i = 0; i < start_key.size(); i++) {
				int idx = start_key[i] - 'a';
				key |= (1 << idx);
			}
		}
		bfs(0, 0);
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}