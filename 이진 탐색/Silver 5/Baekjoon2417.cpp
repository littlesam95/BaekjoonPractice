#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

// ���� Ž������ �ߴµ� 99%���� �ð��ʰ���. ������ �𸣰���.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned long long n;
	cin >> n;
	unsigned long long left = 0;
	unsigned long long right = sqrt(n);
	unsigned long long mid;
	while (left <= right) {
		mid = (left + right) / 2;

		if (mid >= sqrt(n)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	};

	if (mid * mid == n) {
		cout << mid << "\n";
	}
	else {
		cout << mid + 1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}