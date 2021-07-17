#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp[1001] = { 0, };
int dp2[1001] = { 0, };
int dp3[1001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N; 
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		int big = 0;
		for (int j = 1; j < i; j++) {
			if ((arr[i] > arr[j]) && (big < dp[j])) {
				big = dp[j];
			}
			dp[i] = big + 1;
		}
	}
	dp2[N] = 1;
	for (int i = N; i >= 1; i--) {
		int big = 0;
		for (int j = N; j > i; j--) {
			if ((arr[i] > arr[j]) && (big < dp2[j])) {
				big = dp2[j];
			}
			dp2[i] = big + 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		dp3[i] = dp[i] + dp2[i] - 1;
		answer = max(answer, dp3[i]);
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}