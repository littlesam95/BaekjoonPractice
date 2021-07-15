#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp[1001] = { 0, };
int answer = 0;
vector<int> vec;

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
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
	int count = answer;
	for (int i = N; i >= 1; i--) {
		if (dp[i] == count) {
			vec.push_back(arr[i]);
			count--;
		}
	}
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}