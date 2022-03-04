#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001

using namespace std;
int N;
int MAP[MAX];
int Rome_number[] = { 1,5,10,50 };
int answer = 0;

void DFS(int Count, int Cur, int Total) {
	if (Count == N) {
		if (MAP[Total] == 0) {
			MAP[Total]++;
			answer++;
		}
		return;
	}

	for (int i = Cur; i < 4; i++) {
		DFS(Count + 1, i, Total + Rome_number[i]);
	}
}

int main() {
	FIRST
	cin >> N;
	DFS(0, 0, 0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}