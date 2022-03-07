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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int T, N;
int MAP[MAX];
bool visited[MAX];
bool Finished[MAX];
int answer;

void Init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		Finished[i] = false;
	}
	answer = 0;
}

void DFS(int X) {
	visited[X] = true;
	int Next = MAP[X];
	if (!visited[Next]) {
		DFS(Next);
	}
	else {
		if (!Finished[Next]) {
			for (int i = Next; i != X; i = MAP[i]) {
				answer++;
			}
			answer++;
		}
	}
	Finished[X] = true;
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		if (visited[i]) {
			continue;
		}
		DFS(i);
	}
}

void Find_Answer() {
	cout << N - answer << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> N;
		Init();
		for (int i = 1; i <= N; i++) {
			cin >> MAP[i];
		}
		Settings();
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}