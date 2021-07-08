#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp[1001] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i - j] + arr[j], dp[i]);
		}
	}

	cout << dp[N] << "\n";

	getchar();
	getchar();
	return 0;
}