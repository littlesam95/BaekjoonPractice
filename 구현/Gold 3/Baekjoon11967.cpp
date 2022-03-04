#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 105
#define INF 2e9

using namespace std;
struct ROOM {
	int Y, X;
};

int N, M;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { 0,0,1,-1 };
int moveX[4] = { 1,-1,0,0 };
vector<ROOM> room[MAX][MAX];
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}

void Switch(int Y, int X, bool &flag, int &res) {
	int size = room[Y][X].size();
	for (int i = 0; i < size; i++) {
		int nextY = room[Y][X][i].Y;
		int nextX = room[Y][X][i].X;
		if (MAP[nextY][nextX] >= 1) {
			continue;
		}
		MAP[nextY][nextX] = 1;
		flag = true;
		res++;
	}
	MAP[Y][X] = 2;
}

int BFS() {
	int answer = 1;
	queue<ROOM> q;
	visited[1][1] = true;
	MAP[1][1] = 1;
	q.push({ 1,1 });
	bool flag = false;

	while (!q.empty()) {
		flag = false;
		int nowY = q.front().Y;
		int nowX = q.front().X;
		q.pop();

		if (MAP[nowY][nowX] != 2) {
			Switch(nowY, nowX, flag, answer);
		}
		if (flag) {
			init();
			visited[nowY][nowX] = true;
			while (!q.empty()) {
				q.pop();
			};
		}
		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N) && (MAP[nextY][nextX] != 0) && (!visited[nextY][nextX])) {
				visited[nextY][nextX] = true;
				q.push({ nextY,nextX });
			}
		}
	};

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int Y, X, A, B;
		cin >> Y >> X >> A >> B;
		room[Y][X].push_back({ A,B });
	}
	cout << BFS() << "\n";

	getchar();
	getchar();
	return 0;
}