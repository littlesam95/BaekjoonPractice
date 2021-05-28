#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int M, N, H;
int arr[101][101][101];
bool visited[101][101][101] = { 0, };
int moveY[6] = { -1,0,1,0,0,0 };
int moveX[6] = { 0,1,0,-1,0,0 };
int moveZ[6] = { 0,0,0,0,1,-1 };
int countNo = 0;
int res = 0;
queue<tuple<int, int, int> > q;

bool ripe() {
	bool b = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k][i] == 0) {
					b = false;
					break;
				}
			}
			if (!b) {
				break;
			}
		}
		if (!b) {
			break;
		}
	}

	return b;
}

int bfs() {
	if (q.empty()) {
		return -1;
	}
	while (!q.empty()) {
		int nowSize = q.size();

		for (int a = 0; a < nowSize; a++) {
			int nowY = get<0>(q.front());
			int nowX = get<1>(q.front());
			int nowZ = get<2>(q.front());

			for (int i = 0; i < 6; i++) {
				int nextY = nowY + moveY[i];
				int nextX = nowX + moveX[i];
				int nextZ = nowZ + moveZ[i];
				if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (nextZ >= 0) && (nextZ < H)) {
					if ((!visited[nextY][nextX][nextZ]) && (arr[nextY][nextX][nextZ] == 0)) {
						arr[nextY][nextX][nextZ] = 1;
						visited[nextY][nextX][nextZ] = true;
						q.push(make_tuple(nextY, nextX, nextZ));
					}
				}
			}
			q.pop();

			if ((q.size() == 0) && ripe()) {
				return res;
			}
			else if ((q.size() == 0) && !ripe()) {
				return -1;
			}
		}
		res++;
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[j][k][i];
				if (arr[j][k][i] == 1) {
					q.push(make_tuple(j, k, i));
				}
				if (arr[j][k][i] == -1) {
					countNo++;
				}
			}
		}
	}

	if (q.size() == (M * N * H - countNo)) {
		cout << 0 << "\n";
	}
	else {
		cout << bfs() << "\n";
	}

	getchar();
	getchar();
	return 0;
}