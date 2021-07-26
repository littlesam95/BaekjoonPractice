#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
long long N, M;
long long arr[100001];

long long calc(long long left, long long right) {
	long long res = right;
	while (left < right) {
		long long mid = (left + right) / 2;
		
		long long tmp = 0;
		for (int i = 0; i < N; i++) {
			tmp += mid / arr[i];
		}

		if (tmp < M) {
			left = mid + 1;
		}
		else {
			res = min(res, mid);
			right = mid;
		}
	};

	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	long long big = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		big = max(big, arr[i]);
	}
	cout << calc(1, big * M) << "\n";

	getchar();
	getchar();
	return 0;
}