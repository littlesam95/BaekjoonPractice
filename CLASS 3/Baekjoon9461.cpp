#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int T;
long long arr[101];

// 숫자가 커지므로, 자료형은 long long으로 한다.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int i = 1; i <= 100; i++) {
		if ((i >= 1) && (i <= 3)) {
			arr[i] = 1;
		}
		else if (i >= 4) {
			arr[i] = arr[i - 3] + arr[i - 2];
		}
	}

	long long N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << arr[N] << "\n";
	}

	getchar();
	getchar();
	return 0;
}