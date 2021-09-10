#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 9

using namespace std;
int N, M;
int num_arr[MAX];
vector<int> vec;
vector<vector<int> > answer;

void dfs(int X, int depth) {
	if (depth == M) {
		answer.push_back(vec);
		return;
	}
	for (int i = X; i <= N; i++) {
		vec.push_back(num_arr[i]);
		dfs(i, depth + 1);
		vec.pop_back();
	}
}

bool comp(vector<int> A, vector<int> B) {
	bool flag = false;
	for (int i = 0; i < M; i++) {
		if (A[i] == B[i]) {
			continue;
		}
		return (A[i] < B[i]);
	}
	return (A[M - 1] < B[M - 1]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num_arr[i];
	}
	sort(num_arr + 1, num_arr + N + 1);
	dfs(1, 0);
	sort(answer.begin(), answer.end(), comp);
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < M; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}