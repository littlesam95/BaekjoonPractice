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
int N, M, Q;
int H[MAX][MAX];
int Water[MAX][MAX];
pair<int, int> Parent[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
bool visited[MAX][MAX];

void Init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Parent[i][j] = make_pair(i, j);
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
	int PAY = PA.first;
	int PAX = PA.second;
	int PBY = PB.first;
	int PBX = PB.second;
	if (H[PAY][PAX] < H[PBY][PBX]) {
		Parent[PB.first][PB.second] = PA;
	}
	else if (H[PAY][PAX] > H[PBY][PBX]) {
		Parent[PA.first][PA.second] = PB;
	}
	else {
		if (Water[PAY][PAX] < Water[PBY][PBX]) {
			Parent[PB.first][PB.second] = PA;
		}
		else if (Water[PAY][PAX] > Water[PBY][PBX]) {
			Parent[PA.first][PA.second] = PB;
		}
	}
}

void Input() {
	cin >> N >> M >> Q;
	Init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> H[i][j];
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= Q; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		H[A][B] -= C;
		Water[A][B] = i;
		for (int j = 0; j < 4; j++) {
			int nextY = A + moveY[j];
			int nextX = B + moveX[j];
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M) && (Water[nextY][nextX] != 0)) {
				if (Find(make_pair(A, B)) != Find(make_pair(nextY, nextX))) {
					Union(make_pair(A, B), make_pair(nextY, nextX));
				}
				else {
					pair<int, int> nextP = Find(make_pair(nextY, nextX));
					if (H[A][B] < H[nextP.first][nextP.second]) {
						Parent[A][B] = make_pair(A, B);
						Union(make_pair(A, B), make_pair(nextY, nextX));
					}
					else if (H[A][B] == H[nextP.first][nextP.second]) {
						if (Water[A][B] < Water[nextP.first][nextP.second]) {
							Parent[A][B] = make_pair(A, B);
							Union(make_pair(A, B), make_pair(nextY, nextX));
						}
					}
				}
			}
		}
		pair<int, int> answer = Find(make_pair(A, B));
		cout << answer.first << " " << answer.second << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}