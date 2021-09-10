#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 21
#define INF 2e9

using namespace std;
int N;
bool player[MAX];
int arr[MAX][MAX];
int answer = INF;

void dfs(int X, int depth) {
	if (depth == N / 2) {
		int start_score = 0;
		int link_score = 0;
		vector<int> start_vec;
		vector<int> link_vec;
		for (int i = 1; i <= N; i++) {
			if (player[i]) {
				start_vec.push_back(i);
			}
			else {
				link_vec.push_back(i);
			}
		}
		for (int i = 0; i < start_vec.size(); i++) {
			for (int j = 0; j < start_vec.size(); j++) {
				if (i == j) {
					continue;
				}
				start_score += arr[start_vec[i]][start_vec[j]];
			}
		}
		for (int i = 0; i < link_vec.size(); i++) {
			for (int j = 0; j < link_vec.size(); j++) {
				if (i == j) {
					continue;
				}
				link_score += arr[link_vec[i]][link_vec[j]];
			}
		}
		answer = min(answer, abs(start_score - link_score));
		return;
	}
	for (int i = X + 1; i <= N; i++) {
		player[i] = true;
		dfs(i, depth + 1);
		player[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}