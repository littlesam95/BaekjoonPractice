#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string dp[10001];

string calc(string A, string B) {
	string answer = "";
	int diff = A.size() - B.size();
	string b = "";
	while (diff--) {
		b += "0";
	};
	b += B;
	string a = A;
	int idx = a.size() - 1;
	int res;
	int div = 0;
	while (idx >= 0) {
		res = 0;
		int sum = (a[idx] - '0') + (b[idx] - '0') + div;
		div = 0;
		if (sum >= 10) {
			div = sum / 10;
			res = sum % 10;
		}
		else {
			res = sum;
		}
		answer += to_string(res);
		idx--;
		if (idx < 0) {
			if (div > 0) {
				answer += to_string(div);
			}
		}
	};
	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	dp[0] = "0";
	dp[1] = "1";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = calc(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n] << "\n";

	getchar();
	getchar();
	return 0;
}