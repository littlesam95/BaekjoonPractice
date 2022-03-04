#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 12
#define INF 1e9

using namespace std;
int N;
int A[MAX];
int Operator[4];
int answer_big = -INF;
int answer_small = INF;

int Calc(int Op, int A, int B) {
	if (Op == 0) {
		return (A + B);
	}
	else if (Op == 1) {
		return (A - B);
	}
	else if (Op == 2) {
		return (A * B);
	}
	else if (Op == 3) {
		return (A / B);
	}
}

void DFS(int Depth, int Sum) {
	if (Depth == N) {
		answer_big = max(answer_big, Sum);
		answer_small = min(answer_small, Sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Operator[i] > 0) {
			Operator[i]--;
			DFS(Depth + 1, Calc(i, Sum, A[Depth]));
			Operator[i]++;
		}
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> Operator[i];
	}
	DFS(1, A[0]);
	cout << answer_big << "\n" << answer_small << "\n";

	getchar();
	getchar();
	return 0;
}