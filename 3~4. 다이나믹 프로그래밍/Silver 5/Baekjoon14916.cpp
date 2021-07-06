#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int n;
int answer = INT_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	int five = 0;
	while (1) {
		if ((n % 2) == 0) {
			int div = n / 2;
			answer = min(answer, (five + div));
		}
		if ((n - 5) >= 0) {
			n -= 5;
			five++;
		}
		else {
			break;
		}
	};

	if (answer == INT_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}