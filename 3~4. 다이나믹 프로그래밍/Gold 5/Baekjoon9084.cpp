#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int N, M;
		int arr[21];
		int dp[10001] = { 0, };
		dp[0] = 1;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		cin >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = arr[i]; j <= M; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}
		cout << dp[M] << "\n";
	};

	getchar();
	getchar();
	return 0;
}