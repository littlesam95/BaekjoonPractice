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
#define MAX 70
#define INF 2e9

using namespace std;
struct ICE {
	int Y, X;
};

int N, Q;
int MAP[MAX][MAX];
int PHASE[1001];
bool visited[MAX][MAX];
int moveY[4] = { 0,0,1,-1 };
int moveX[4] = { 1,-1,0,0 };
long long answer_sum = 0;
int answer_size = 0;

int Change_Dir(int D) {
	if (D == 0) {
		return 3;
	}
	else if (D == 1) {
		return 2;
	}
	else if (D == 2) {
		return 0;
	}
	else if (D == 3) {
		return 1;
	}
}

void Turning(int Y, int X, int L) {
	int cnt = L / 2;
	for (int i = 0; i < cnt; i++) {
		int startY = Y + i;
		int endY = Y + L - i - 1;
		int startX = X + i;
		int endX = X + L - i - 1;

		int Y_IDX = endY;
		int X_IDX = startX;
		int IDX = 0;
		vector<int> tmp;
		for (int j = startY; j < endY; j++) { // 왼쪽 열에 있는 얼음을 저장(위에서부터 아래로)
			tmp.push_back(MAP[j][startX]);
		}
		for (int j = startY; j < endY; j++) {
			MAP[j][startX] = MAP[endY][X_IDX++];
		}
		for (int j = startX; j < endX; j++) {
			MAP[endY][j] = MAP[Y_IDX--][endX];
		}
		for (int j = endY; j > startY; j--) {
			MAP[j][endX] = MAP[startY][X_IDX--];
		}
		for (int j = endX; j > startX; j--) {
			MAP[startY][j] = tmp[IDX++];
		}
	}
}

void Rotation_Map(int L) {
	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			Turning(i, j, L);
		}
	}
}

void Ice_Melt() {
	vector<ICE> vec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] >= 1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextY = i + moveY[k];
					int nextX = j + moveX[k];
					if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && (MAP[nextY][nextX] >= 1)) {
						cnt++;
					}
				}
				if (cnt < 3) {
					vec.push_back({ i,j });
				}
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int Y = vec[i].Y;
		int X = vec[i].X;
		MAP[Y][X]--;
		answer_sum--;
	}
}

int ICE_Calculation(int Y, int X) {
	int size = 0;
	queue<ICE> q;
	visited[Y][X] = true;
	q.push({ Y,X });

	while (!q.empty()) {
		int nowY = q.front().Y;
		int nowX = q.front().X;
		size++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && (MAP[nextY][nextX] >= 1) && (!visited[nextY][nextX])) {
				visited[nextY][nextX] = true;
				q.push({ nextY,nextX });
			}
		}
	};

	return size;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	N = (1 << N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			answer_sum += MAP[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> PHASE[i];
	}
	for (int i = 0; i < Q; i++) {
		int L = (1 << PHASE[i]);
		Rotation_Map(L);
		Ice_Melt();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && (MAP[i][j] >= 1)) {
				answer_size = max(answer_size, ICE_Calculation(i, j));
			}
		}
	}
	cout << answer_sum << "\n";
	cout << answer_size << "\n";

	getchar();
	getchar();
	return 0;
}