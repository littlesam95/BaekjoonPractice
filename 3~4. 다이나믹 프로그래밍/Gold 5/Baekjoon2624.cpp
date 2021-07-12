#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T, K;
vector<pair<int, int> > vec;
int dp[10001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int p, n;
		cin >> p >> n;
		vec.push_back(make_pair(p, n));
	}
	dp[0] = 1;
	for (int i = 0; i < K; i++) {
		int v = vec[i].first;
		int c = vec[i].second;
		for (int j = T; j >= 0; j--) {
			for (int k = 1; (k <= c) && (j - v * k >= 0); k++) {
				dp[j] += dp[j - v * k];
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";

	cout << dp[T] << "\n";

	getchar();
	getchar();
	return 0;
}

// 진짜 모르겠어서 https://nicotina04.tistory.com/15 참고함.