#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 11
#define INF 2e9

using namespace std;
int arr[MAX][MAX];
int answer = -1;

void DFS(int Y, int X, int paper, int one, int two, int three, int four, int five) {
	if (Y == 10) {
		bool flag = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] == 1) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			if (answer == -1) {
				answer = max(answer, paper);
			}
			else {
				answer = min(answer, paper);
			}
		}
		return;
	}
	int nextY = Y;
	int nextX = X;
	if (X == 9) {
		nextY++;
		nextX = 0;
	}
	else {
		nextX++;
	}
	if (arr[Y][X] == 1) {
		if (one > 0) {
			bool flag = true;
			for (int i = Y; i <= Y; i++) {
				for (int j = X; j <= X; j++) {
					if (arr[i][j] != 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = Y; i <= Y; i++) {
					for (int j = X; j <= X; j++) {
						arr[i][j] = 0;
					}
				}
				DFS(nextY, nextX, paper + 1, one - 1, two, three, four, five);
				for (int i = Y; i <= Y; i++) {
					for (int j = X; j <= X; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}
		if (two > 0) {
			bool flag = true;
			for (int i = Y; i <= Y + 1; i++) {
				for (int j = X; j <= X + 1; j++) {
					if (arr[i][j] != 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = Y; i <= Y + 1; i++) {
					for (int j = X; j <= X + 1; j++) {
						arr[i][j] = 0;
					}
				}
				DFS(nextY, nextX, paper + 1, one, two - 1, three, four, five);
				for (int i = Y; i <= Y + 1; i++) {
					for (int j = X; j <= X + 1; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}
		if (three > 0) {
			bool flag = true;
			for (int i = Y; i <= Y + 2; i++) {
				for (int j = X; j <= X + 2; j++) {
					if (arr[i][j] != 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = Y; i <= Y + 2; i++) {
					for (int j = X; j <= X + 2; j++) {
						arr[i][j] = 0;
					}
				}
				DFS(nextY, nextX, paper + 1, one, two, three - 1, four, five);
				for (int i = Y; i <= Y + 2; i++) {
					for (int j = X; j <= X + 2; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}
		if (four > 0) {
			bool flag = true;
			for (int i = Y; i <= Y + 3; i++) {
				for (int j = X; j <= X + 3; j++) {
					if (arr[i][j] != 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = Y; i <= Y + 3; i++) {
					for (int j = X; j <= X + 3; j++) {
						arr[i][j] = 0;
					}
				}
				DFS(nextY, nextX, paper + 1, one, two, three, four - 1, five);
				for (int i = Y; i <= Y + 3; i++) {
					for (int j = X; j <= X + 3; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}
		if (five > 0) {
			bool flag = true;
			for (int i = Y; i <= Y + 4; i++) {
				for (int j = X; j <= X + 4; j++) {
					if (arr[i][j] != 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = Y; i <= Y + 4; i++) {
					for (int j = X; j <= X + 4; j++) {
						arr[i][j] = 0;
					}
				}
				DFS(nextY, nextX, paper + 1, one, two, three, four, five - 1);
				for (int i = Y; i <= Y + 4; i++) {
					for (int j = X; j <= X + 4; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}
	}
	else {
		DFS(nextY, nextX, paper, one, two, three, four, five);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 0, 0, 5, 5, 5, 5, 5);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}