#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int dp[1000001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		dp[num] = dp[num - 1] + 1;
	}
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << N - answer << "\n";

	getchar();
	getchar();
	return 0;
}