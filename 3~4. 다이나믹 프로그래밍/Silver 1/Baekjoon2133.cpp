#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int dp[31];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[N] << "\n";

	getchar();
	getchar();
	return 0;
}

// 진짜 모르겠어서 https://kosaf04pyh.tistory.com/236 참고함.