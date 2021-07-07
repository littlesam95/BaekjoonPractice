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
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
	}
	for (int i = 0; i < N; i++) {
		int big = 0;
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[j] < arr[i]) && (big < dp[j])) {
				big = dp[j];
			}
		}
		dp[i] = big + arr[i];
	}
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}