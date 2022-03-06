#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int R, C, HR, HC;
string Tour;
char MAP[MAX][MAX];
pair<int, int> Parent[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
char answer[MAX][MAX];
bool Here[MAX][MAX];

void Init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			Parent[i][j] = make_pair(i, j);
			answer[i][j] = '#';
		}
	}
}

pair<int, int> Find(pair<int, int> A) {
	if (Parent[A.first][A.second] == make_pair(A.first, A.second)) {
		return make_pair(A.first, A.second);
	}
	return Parent[A.first][A.second] = Find(Parent[A.first][A.second]);
}

void Union(pair<int, int> A, pair<int, int> B) {
	pair<int, int> PA = Find(A);
	pair<int, int> PB = Find(B);
	if (PA != PB) {
		Parent[PB.first][PB.second] = PA;
	}
}

void BFS(int Y, int X) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(Y, X));
	visited[Y][X] = true;

	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		if (Find(make_pair(CurY, CurX)) != Find(make_pair(Y, X))) {
			Union(make_pair(Y, X), make_pair(CurY, CurX));
		}

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && !visited[nextY][nextX] && (MAP[CurY][CurX] == MAP[nextY][nextX])) {
				visited[nextY][nextX] = true;
				Q.push(make_pair(nextY, nextX));
			}
		}
	};
}

void Input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= C; j++) {
			MAP[i][j] = S[j - 1];
		}
	}
	Init();
	cin >> HR >> HC;
	cin >> Tour;
}

void Settings() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
			}
		}
	}
	for (int i = 0; i < Tour.size(); i++) {
		int CMD = Tour[i];
		if (CMD == 'U') {
			HR--;
		}
		else if (CMD == 'D') {
			HR++;
		}
		else if (CMD == 'L') {
			HC--;
		}
		else if (CMD == 'R') {
			HC++;
		}
		else if (CMD == 'W') {
			pair<int, int> P = Find(make_pair(HR, HC));
			answer[P.first][P.second] = '.';
		}
	}
	Here[HR][HC] = true;
	for (int i = 0; i < 4; i++) {
		Here[HR + moveY[i]][HC + moveX[i]] = true;
	}
}

void Find_Answer() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (Here[i][j]) {
				cout << '.';
			}
			else {
				pair<int, int> P = Find(make_pair(i, j));
				if (answer[i][j] == '#') {
					cout << answer[P.first][P.second];
				}
				else {
					cout << answer[i][j];
				}
			}
		}
		cout << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}