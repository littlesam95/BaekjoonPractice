#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[1000];
int dp[1000];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[N - 1] = 1;
	for (int i = N - 1; i >= 0; i--) {
		int big = 0;
		for (int j = N - 1; j > i; j--) {
			if ((arr[i] > arr[j]) && (big < dp[j])) {
				big = dp[j];
			}
			dp[i] = big + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}