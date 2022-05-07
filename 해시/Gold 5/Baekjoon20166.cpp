#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
char MAP[MAX][MAX];
unordered_map<string, int> UM;
vector<string> Answer;

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = S[j];
		}
	}
	while (K--) {
		string Like;
		cin >> Like;
		UM.insert(make_pair(Like, 0));
		Answer.push_back(Like);
	};
}

void DFS(int Y, int X, string S) {
	if (S.size() > 5) {
		return;
	}
	if (UM.find(S) != UM.end()) {
		UM[S]++;
	}
	int nextY, nextX;
	// »ó
	nextY = Y - 1;
	if (nextY == -1) {
		nextY = N - 1;
	}
	nextX = X;
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// ÇÏ
	nextY = Y + 1;
	if (nextY == N) {
		nextY = 0;
	}
	nextX = X;
	DFS(nextY, nextX, S + MAP[nextY][nextX]);
	
	// ÁÂ
	nextY = Y;
	nextX = X - 1;
	if (nextX == -1) {
		nextX = M - 1;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// ¿ì
	nextY = Y;
	nextX = X + 1;
	if (nextX == M) {
		nextX = 0;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// ºÏ¼­
	nextY = Y - 1;
	if (nextY == -1) {
		nextY = N - 1;
	}
	nextX = X - 1;
	if (nextX == -1) {
		nextX = M - 1;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// µ¿ºÏ
	nextY = Y - 1;
	if (nextY == -1) {
		nextY = N - 1;
	}
	nextX = X + 1;
	if (nextX == M) {
		nextX = 0;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// ³²¼­
	nextY = Y + 1;
	if (nextY == N) {
		nextY = 0;
	}
	nextX = X - 1;
	if (nextX == -1) {
		nextX = M - 1;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);

	// µ¿³²
	nextY = Y + 1;
	if (nextY == N) {
		nextY = 0;
	}
	nextX = X + 1;
	if (nextX == M) {
		nextX = 0;
	}
	DFS(nextY, nextX, S + MAP[nextY][nextX]);
}

void Settings() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			string S = "";
			S += MAP[i][j];
			DFS(i, j, S);
		}
	}
}

void Find_Answer() {
	for (int i = 0; i < Answer.size(); i++) {
		cout << UM[Answer[i]] << "\n";
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