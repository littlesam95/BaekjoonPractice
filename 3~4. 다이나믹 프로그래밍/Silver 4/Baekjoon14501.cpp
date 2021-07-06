#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > vec;
int answer = 0;

void dfs(int day, int money) {
	if (day >= N) {
		answer = max(answer, money);
		return;
	}

	for (int i = (day + vec[day].first); i <= N; i++) {
		dfs(i, money + vec[day].second);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back(make_pair(n1, n2));
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0);
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}

// DP문제였지만 DFS로 풀었음.