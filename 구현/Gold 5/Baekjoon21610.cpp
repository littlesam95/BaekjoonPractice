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
struct Cloud {
	int Y, X;
};

int N, M;
int A[MAX][MAX];
bool cloud_maked[MAX][MAX];
vector<Cloud> cloud;
int moveY[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int moveX[9] = { 0,-1,-1,0,1,1,1,0,-1 };
long long answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cloud_maked[i][j] = false;
		}
	}
}

int Find_Dist(int X) {
	if (X < 1) {
		return N;
	}
	if (X > N) {
		return 1;
	}
	return X;
}

void Cloud_Move(int D, int S) {
	for (int i = 0; i < cloud.size(); i++) {
		int Y = cloud[i].Y;
		int X = cloud[i].X;
		int nextY = Y;
		int nextX = X;
		for (int j = 0; j < S; j++) {
			nextY += moveY[D];
			nextX += moveX[D];
			nextY = Find_Dist(nextY);
			nextX = Find_Dist(nextX);
		}
		cloud[i].Y = nextY;
		cloud[i].X = nextX;
	}
}

void Raining() {
	for (int i = 0; i < cloud.size(); i++) {
		int Y = cloud[i].Y;
		int X = cloud[i].X;
		A[Y][X]++;
	}
}

void Copy_Arr(int tmp[][MAX]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tmp[i][j] = A[i][j];
		}
	}
}

void Copy_Water() {
	int tmpA[MAX][MAX];
	Copy_Arr(tmpA);
	for (int i = 0; i < cloud.size(); i++) {
		int Y = cloud[i].Y;
		int X = cloud[i].X;
		int R = 0;
		for (int j = 2; j <= 8; j += 2) {
			int nextY = Y + moveY[j];
			int nextX = X + moveX[j];
			if ((nextY < 1) || (nextY > N) || (nextX < 1) || (nextX > N)) {
				continue;
			}
			if (tmpA[nextY][nextX] >= 1) {
				R++;
			}
		}
		A[Y][X] += R;
	}
}

void Cloud_Erase() {
	for (int i = 0; i < cloud.size(); i++) {
		int Y = cloud[i].Y;
		int X = cloud[i].X;
		cloud_maked[Y][X] = true;
	}
	cloud.clear();
}

void Cloud_Make() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((!cloud_maked[i][j]) && (A[i][j] >= 2)) {
				cloud.push_back({ i,j });
				A[i][j] -= 2;
			}
		}
	}
	init();
}

void Sum_Water() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += A[i][j];
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
			cin >> A[i][j];
		}
	}
	cloud.push_back({ N,1 });
	cloud.push_back({ N,2 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 1,2 });
	for (int i = 0; i < M; i++) {
		int D, S;
		cin >> D >> S;
		Cloud_Move(D, S);
		Raining();
		Copy_Water();
		Cloud_Erase();
		Cloud_Make();
	}
	Sum_Water();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}