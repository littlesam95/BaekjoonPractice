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
#define MAX 10001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
int A[MAX];
int Parent[MAX];
bool visited[MAX];
int answer = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (A[PX] <= A[PY]) {
		Parent[PY] = PX;
		A[PY] = A[PX];
	}
	else {
		Parent[PX] = PY;
		A[PX] = A[PY];
	}
}

void Input() {
	cin >> N >> M >> K;
	Init();
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		int V, W;
		cin >> V >> W;
		if (Find(V) != Find(W)) {
			Union(V, W);
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		int P = Find(i);
		if (!visited[P]) {
			visited[P] = true;
			answer += A[P];
		}
	}
}


void Find_Answer() {
	if (answer <= K) {
		cout << answer << "\n";
	}
	else {
		cout << "Oh no\n";
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