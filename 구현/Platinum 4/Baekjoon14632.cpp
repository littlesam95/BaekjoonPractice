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
#define MAX 1005
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K, Q;
pair<int, int> Pos[MAX];
string MAP[MAX][MAX];
char Picture[MAX][MAX];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Picture[i][j] = '.';
		}
	}
}

void Stamping(int MAP_Number, int Y, int X) {
	int H = Pos[MAP_Number].first;
	int W = Pos[MAP_Number].second;
	int CurY = 0;
	int CurX = 0;
	for (int i = Y; i < (Y + H); i++) {
		for (int j = X; j < (X + W); j++) {
			Picture[i][j] = MAP[MAP_Number][CurY][CurX++];
		}
		CurY++;
		CurX = 0;
	}
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Picture[i][j];
		}
		cout << "\n";
	}
}

int main() {
	FIRST
	cin >> N >> M;
	init();
	cin >> K;
	for (int i = 0; i < K; i++) {
		int H, W;
		cin >> H >> W;
		Pos[i + 1] = make_pair(H, W);
		for (int j = 0; j < H; j++) {
			cin >> MAP[i + 1][j];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int T, Y, X;
		cin >> T >> Y >> X;
		Stamping(T, Y, X);
	}
	Print();

	getchar();
	getchar();
	return 0;
}