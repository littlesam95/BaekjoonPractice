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

int H, W;
int arr[1000][1000];
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
queue<Info> q;
int day = 0;

void bfs() {
	while (1) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int next_y = now_y + moveY[i];
				int next_x = now_x + moveX[i];
				if ((next_y >= 0) && (next_y < H) && (next_x >= 0) && (next_x < W)) {
					if (arr[next_y][next_x] > 0) {
						arr[next_y][next_x]--;
						if (arr[next_y][next_x] == 0) {
							q.push({ next_y,next_x });
						}
					}
				}
			}
		}
		if (q.empty()) {
			break;
		}
		day++;
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char num;
			cin >> num;
			if (num == '.') {
				arr[i][j] = 0;
				q.push({ i,j });
			}
			else {
				arr[i][j] = num - '0';
			}
		}
	}
	bfs();
	cout << day << "\n";

	getchar();
	getchar();
	return 0;
}