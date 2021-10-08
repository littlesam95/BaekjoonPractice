#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 11
#define ISLAND_MAX 7
#define INF 2e9

using namespace std;
int N, M;
int Island = 1; // 섬의 개수
int MAP[MAX][MAX];
int MAP_INDEX[MAX][MAX];
int ISLAND_DIST[ISLAND_MAX][ISLAND_MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

vector<pair<int, int> > Pos;
vector<pair<int, int> > Island_Pos[ISLAND_MAX];

int parent[MAX];
vector<pair<int, pair<int, int> > > Edge;
int answer = 0;

void init() {
	for (int i = 0; i < ISLAND_MAX; i++) {
		parent[i] = -1;
	}
	for (int i = 0; i < ISLAND_MAX; i++) {
		for (int j = 0; j < ISLAND_MAX; j++) {
			ISLAND_DIST[i][j] = INF;
		}
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

void BFS(int Y, int X, int Number) {
	queue<pair<int, int> > q;
	visited[Y][X] = true;
	MAP_INDEX[Y][X] = Number;
	q.push(make_pair(Y, X));
	Island_Pos[Number].push_back(make_pair(Y, X));

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (visited[nextY][nextX]) || (MAP[nextY][nextX] != 1)) {
				continue;
			}
			MAP_INDEX[nextY][nextX] = Number;
			visited[nextY][nextX] = true;
			q.push(make_pair(nextY, nextX));
			Island_Pos[Number].push_back(make_pair(nextY, nextX));
		}
	};
}

void DFS(int Y, int X, int D, int B_Size, int S, int E) {
	int nextY = Y + moveY[D];
	int nextX = X + moveX[D];
	if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
		return;
	}
	if (MAP[nextY][nextX] == 0) {
		DFS(nextY, nextX, D, B_Size + 1, S, E);
	}
	else if (MAP[nextY][nextX] == 1) {
		if (MAP_INDEX[nextY][nextX] == E) {
			if (B_Size > 1) {
				if (ISLAND_DIST[S][E] > B_Size) {
					ISLAND_DIST[S][E] = B_Size;
					ISLAND_DIST[E][S] = B_Size;
				}
				return;
			}
		}
		else {
			return;
		}
	}
}

void MakeBridge(int S, int E) {
	for (int i = 0; i < Island_Pos[S].size(); i++) {
		int Y = Island_Pos[S][i].first;
		int X = Island_Pos[S][i].second;
		for (int j = 0; j < 4; j++) {
			int nextY = Y + moveY[j];
			int nextX = X + moveX[j];
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
				continue;
			}
			if (MAP[nextY][nextX] == 0) {
				DFS(Y, X, j, 0, S, E);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				Pos.push_back(make_pair(i, j));
			}
		}
	}
	// 각 섬마다 번호 붙이기
	for (int i = 0; i < Pos.size(); i++) {
		int Y = Pos[i].first;
		int X = Pos[i].second;
		if (!visited[Y][X]) {
			BFS(Y, X, Island);
			Island++;
		}
	}
	// 길이 2 이상의 최단 거리의 다리 연결하기
	for (int i = 1; i < Island; i++) {
		for (int j = i + 1; j < Island; j++) {
			MakeBridge(i, j);
			if (ISLAND_DIST[i][j] == INF) {
				continue;
			}
			Edge.push_back(make_pair(ISLAND_DIST[i][j], make_pair(i, j)));
		}
	}
	// MST를 이용하여 모든 섬을 연결하는 다리 길이의 최솟값 구하기
	sort(Edge.begin(), Edge.end());
	int E = 0;
	for (int i = 0; i < Edge.size(); i++) {
		int A = Edge[i].second.first;
		int B = Edge[i].second.second;
		int C = Edge[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += C;
			E++;
		}
		if (E == Island - 2) {
			break;
		}
	}
	if (E == Island - 2) { // 모든 섬을 연결하는 것이 가능한 경우
		cout << answer << "\n";
	}
	else { // 모든 섬을 연결하는 것이 불가능한 경우
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}