#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 500005
#define LL long long
#define INF 2e9

using namespace std;
int N, A, B;
int visitedA[MAX][21];
int visitedB[MAX][21];

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 21; j++) {
			visitedA[i][j] = -1;
			visitedB[i][j] = -1;
		}
	}
}

void BFS_A() {
	queue<pair<int, int> > Q;
	visitedA[A][0] = 0;
	Q.push(make_pair(A, 0));

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurDay = Q.front().second;
		Q.pop();

		int nextX;
		// 왼쪽으로 이동
		nextX = CurX - (int)pow(2, CurDay);
		if ((nextX >= 1) && (nextX <= N) && (visitedA[nextX][CurDay + 1] == -1)) {
			visitedA[nextX][CurDay + 1] = CurDay + 1;
			Q.push(make_pair(nextX, CurDay + 1));
		}

		// 오른쪽으로 이동
		nextX = CurX + (int)pow(2, CurDay);
		if ((nextX >= 1) && (nextX <= N) && (visitedA[nextX][CurDay + 1] == -1)) {
			visitedA[nextX][CurDay + 1] = CurDay + 1;
			Q.push(make_pair(nextX, CurDay + 1));
		}
	};
}

int BFS_B() {
	queue<pair<int, int> > Q;
	visitedA[B][0] = 0;
	Q.push(make_pair(B, 0));

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurDay = Q.front().second;
		Q.pop();

		if ((visitedA[CurX][CurDay] != -1) && (visitedA[CurX][CurDay] == visitedB[CurX][CurDay])) {
			return CurDay;
		}

		int nextX;
		// 왼쪽으로 이동
		nextX = CurX - (int)pow(2, CurDay);
		if ((nextX >= 1) && (nextX <= N) && (visitedB[nextX][CurDay + 1] == -1)) {
			visitedB[nextX][CurDay + 1] = CurDay + 1;
			Q.push(make_pair(nextX, CurDay + 1));
		}

		// 오른쪽으로 이동
		nextX = CurX + (int)pow(2, CurDay);
		if ((nextX >= 1) && (nextX <= N) && (visitedB[nextX][CurDay + 1] == -1)) {
			visitedB[nextX][CurDay + 1] = CurDay + 1;
			Q.push(make_pair(nextX, CurDay + 1));
		}
	};

	return -1;
}

int main() {
	FIRST
	init();
	cin >> N >> A >> B;
	BFS_A();
	cout << BFS_B() << "\n";

	getchar();
	getchar();
	return 0;
}