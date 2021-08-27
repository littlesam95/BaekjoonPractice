#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 501

using namespace std;
int R, C;
int arr[MAX][MAX];
int dp[MAX * MAX];
int parent[MAX * MAX];
int moveY[8] = { -1,-1,-1,0,1,1,1,0 };
int moveX[8] = { -1,0,1,1,1,0,-1,-1 };

int dfs(int X) {
	if (parent[X] == X) {
		return X;
	}
	else {
		return parent[X] = dfs(parent[X]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int y = i;
			int x = j;
			for (int k = 0; k < 8; k++) {
				int next_y = i + moveY[k];
				int next_x = j + moveX[k];
				if ((next_y >= 0) && (next_y < R) && (next_x >= 0) && (next_x < C)) {
					if (arr[next_y][next_x] < arr[y][x]) {
						y = next_y;
						x = next_x;
					}
				}
			}
			parent[i * C + j] = y * C + x;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dp[dfs(i * C + j)]++;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << dp[i * C + j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}