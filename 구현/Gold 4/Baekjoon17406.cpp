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
#define MAX 51
#define INF 2e9

using namespace std;
struct Query {
	int R, C, S;
};

int N, M, K;
int A[MAX][MAX];
vector<Query> query;
vector<int> order;
bool checked[7];
int moveY[4] = { 0,0,1,-1 };
int moveX[4] = { 1,-1,0,0 };
int answer = INF;

void Copy_Arr(int tmp[][MAX]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = A[i][j];
		}
	}
}

void Return_Arr(int tmp[][MAX]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

int Find_Value() {
	int res = INF;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += A[i][j];
		}
		res = min(res, sum);
	}
	return res;
}

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

void Make_Rotation(Query Q) {
	int startY = Q.R - Q.S;
	int endY = Q.R + Q.S;
	int startX = Q.C - Q.S;
	int endX = Q.C + Q.S;
	int cnt = (endY - startY) / 2;

	for (int i = 0; i < cnt; i++) {
		int Y = startY;
		int X = startX;
		int tmp = A[Y][X];
		int D = 2;
		while (1) {
			int nextY = Y + moveY[D];
			int nextX = X + moveX[D];
			if ((nextY == startY) && (nextX == startX)) {
				A[Y][X] = tmp;
				break;
			}
			if ((startY <= nextY) && (nextY <= endY - i) && (startX <= nextX) && (nextX <= endX - i)) {
				A[Y][X] = A[nextY][nextX];
				Y = nextY;
				X = nextX;
			}
			else {
				D = Change_Dir(D);
			}
		};
		startY++;
		startX++;
	}
}

void Rotate_Arr(int depth) {
	if (depth == K) {
		int tmpA[MAX][MAX];
		Copy_Arr(tmpA);
		for (int i = 0; i < order.size(); i++) {
			Make_Rotation(query[order[i]]);
		}
		answer = min(answer, Find_Value());
		Return_Arr(tmpA);
		return;
	}
	for (int i = 0; i < query.size(); i++) {
		if (!checked[i]) {
			checked[i] = true;
			order.push_back(i);
			Rotate_Arr(depth + 1);
			order.pop_back();
			checked[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int R, C, S;
		cin >> R >> C >> S;
		query.push_back({ R,C,S });
	}
	Rotate_Arr(0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}