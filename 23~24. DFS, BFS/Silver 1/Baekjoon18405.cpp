#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, K, S, X, Y;
int arr[201][201] = { 0, };
bool visited[201][201] = { false, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

typedef struct {
	int y;
	int x;
	int sec;
} virus;

vector<virus> vec;

bool comp(virus A, virus B) {
	if (A.sec < B.sec) {
		return true;
	}
	else {
		return false;
	}
}

void bfs(int s, int y, int x) {
	int second = 0;

	while (1) {
		if (arr[y - 1][x - 1] != 0) {
			cout << arr[y - 1][x - 1] << "\n";
			break;
		}
		if (second == s) {
			cout << 0 << "\n";
			break;
		}

		vec.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {
					virus tmp;
					tmp.y = i;
					tmp.x = j;
					tmp.sec = arr[i][j];
					vec.push_back(tmp);
				}
			}
		}

		sort(vec.begin(), vec.end(), comp);

		int size = vec.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 4; j++) {
				int nextY = vec[i].y + moveY[j];
				int nextX = vec[i].x + moveX[j];
				if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N)) {
					if ((!visited[nextY][nextX])) {
						visited[nextY][nextX] = true;
						arr[nextY][nextX] = arr[vec[i].y][vec[i].x];
					}
				}
			}
		}
		second++;
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				visited[i][j] = true;
			}
		}
	}
	cin >> S >> X >> Y;
	bfs(S, X, Y);

	getchar();
	getchar();
	return 0;
}