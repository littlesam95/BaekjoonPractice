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
#define MAX 25
#define INF 2e9

using namespace std;
struct BLOCK_INFO {
	int SIZE, RAINBOWSIZE, Y, X;
	vector<pair<int, int> > BLOCK_POS;
};

int N, M;
int MAP[MAX][MAX];
bool Rainbow_visited[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
long long answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Rainbow_visited[i][j] = false;
		}
	}
}

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		return (A.second < B.second);
	}
	return (A.first < B.first);
}

bool Block_Compare(BLOCK_INFO A, BLOCK_INFO B) {
	if (A.SIZE == B.SIZE) {
		if (A.RAINBOWSIZE == B.RAINBOWSIZE) {
			if (A.Y == B.Y) {
				return (A.X > B.X);
			}
			return (A.Y > B.Y);
		}
		return (A.RAINBOWSIZE > B.RAINBOWSIZE);
	}
	return (A.SIZE > B.SIZE);
}

BLOCK_INFO BFS(int Y, int X) {
	init();
	int Rainbow_Size = 0;
	int Color = MAP[Y][X];
	vector<pair<int, int> > block_vec;
	vector<pair<int, int> > not_rainbow_vec;
	block_vec.push_back(make_pair(Y, X));
	not_rainbow_vec.push_back(make_pair(Y, X));
	queue<pair<int, int> > q;
	q.push(make_pair(Y, X));
	visited[Y][X] = true;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY < 1) || (nextY > N) || (nextX < 1) || (nextX > N)) {
				continue;
			}
			if (MAP[nextY][nextX] == 0) {
				if (!Rainbow_visited[nextY][nextX]) {
					Rainbow_visited[nextY][nextX] = true;
					Rainbow_Size++;
					q.push(make_pair(nextY, nextX));
					block_vec.push_back(make_pair(nextY, nextX));
				}
			}
			else if (MAP[nextY][nextX] == Color) {
				if (!visited[nextY][nextX]) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
					block_vec.push_back(make_pair(nextY, nextX));
					not_rainbow_vec.push_back(make_pair(nextY, nextX));
				}
			}
		}
	};

	sort(not_rainbow_vec.begin(), not_rainbow_vec.end(), comp);
	BLOCK_INFO res;
	res.SIZE = block_vec.size();
	res.RAINBOWSIZE = Rainbow_Size;
	res.Y = not_rainbow_vec[0].first;
	res.X = not_rainbow_vec[0].second;
	res.BLOCK_POS = block_vec;
	return res;
}

BLOCK_INFO Find_Big_Block() {
	memset(visited, false, sizeof(visited));
	BLOCK_INFO res;
	res.SIZE = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				if ((MAP[i][j] != 0) && (MAP[i][j] != -1) && (MAP[i][j] != -2)) {
					BLOCK_INFO tmp = BFS(i, j);
					if (res.SIZE == -1) {
						res = tmp;
					}
					else {
						if (Block_Compare(tmp, res)) {
							res = tmp;
						}
					}
				}
			}
		}
	}
	return res;
}

void Remove_Block(BLOCK_INFO A) {
	int size = A.BLOCK_POS.size();
	for (int i = 0; i < size; i++) {
		int Y = A.BLOCK_POS[i].first;
		int X = A.BLOCK_POS[i].second;
		MAP[Y][X] = -2;
	}
	answer += (size * size);
}

void Gravity_Work() {
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			if ((MAP[i][j] == -2) || (MAP[i][j] == -1)) {
				continue;
			}
			int Color = MAP[i][j];
			int nextY = i + 1;
			while (1) {
				if (MAP[nextY][j] != -2) {
					break;
				}
				if (nextY > N) {
					break;
				}
				nextY++;
			};
			nextY--;
			MAP[i][j] = -2;
			MAP[nextY][j] = Color;
		}
	}
}

void Rotate_Map() {
	for (int i = 1; i <= (N / 2); i++) {
		int startY = i;
		int startX = i;
		int endY = N - i + 1;
		int endX = N - i + 1;
		int Y_IDX = endY;
		int X_IDX = startX;
		int IDX = 0;
		vector<int> tmp;
		for (int y = endY; y > startY; y--) {
			tmp.push_back(MAP[y][startX]);
		}
		for (int x = startX; x < endX; x++) {
			MAP[Y_IDX--][startX] = MAP[startY][x];
		}
		for (int y = startY; y < endY; y++) {
			MAP[startY][X_IDX++] = MAP[y][endX];
		}
		for (int x = endX; x > startX; x--) {
			MAP[Y_IDX++][endX] = MAP[endY][x];
		}
		for (int x = endX; x > startX; x--) {
			MAP[endY][x] = tmp[IDX++];
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	while (1) {
		// 1. 크기가 가장 큰 블록 그룹을 찾는다.
		BLOCK_INFO Result = Find_Big_Block();
		if (Result.SIZE < 2) {
			break;
		}
		// 2. 블록을 제거하고 점수를 획득한다.
		Remove_Block(Result);
		// 3. 중력 작용
		Gravity_Work();
		// 4. 격자 회전
		Rotate_Map();
		// 5. 다시 중력 작용
		Gravity_Work();
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}