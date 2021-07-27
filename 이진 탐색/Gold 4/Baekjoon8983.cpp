#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int M, N, L;
int arr[100001];
int answer = 0;

void calc() {
	int y, x;
	cin >> y >> x;
	if (x > L) {
		return;
	}
	int upper = y + L - x;
	int lower = y + x - L;
	int low = 0;
	int high = M - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if ((lower <= arr[mid]) && (arr[mid] <= upper)) {
			answer++;
			break;
		}
		else if (arr[mid] < lower) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + M);
	for (int i = 0; i < N; i++) {
		calc();
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}