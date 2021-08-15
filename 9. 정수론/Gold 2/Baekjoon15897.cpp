#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	N--;
	for (int i = N + 1; i != 0; i = N / ((N / i) + 1)) { // i = 12, 11, 5, 3, 2, 1
		answer += (N / i + 1) * (i - (N / ((N / i) + 1))); // 횟수 * 횟수에 해당하는 숫자의 개수
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}