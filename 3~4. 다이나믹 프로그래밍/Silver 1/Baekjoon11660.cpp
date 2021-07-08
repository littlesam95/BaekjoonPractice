#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int arr[1025][1025];
int dp[1025][1025] = { 0, };
vector<pair<pair<int, int>, pair<int, int> > > vec;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	for (int i = 1; i <= N; i++) {
		dp[i][1] = arr[i][1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for (int t = 0; t < vec.size(); t++) {
		int answer = 0;
		for (int i = vec[t].first.first; i <= vec[t].second.first; i++) {
			answer += (dp[i][vec[t].second.second] - dp[i][vec[t].first.second - 1]);
		}
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}