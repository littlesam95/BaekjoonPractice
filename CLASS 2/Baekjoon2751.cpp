#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// 시간이 오래 걸리므로, 시간복잡도가 O(nlogn)인 병합 정렬을 사용
void SORT(int*arr, int*arr2, int left, int mid, int right) {
	int a = left;
	int b = mid + 1;
	int c = left;

	while ((a <= mid) && (b <= right)) {
		if (arr[a] < arr[b]) {
			arr2[c] = arr[a++];
		}
		else {
			arr2[c] = arr[b++];
		}
		c++;
	}

	if (a > mid) {
		while (b <= right) {
			arr2[c++] = arr[b++];
		}
	}
	if (b > right) {
		while (a <= mid) {
			arr2[c++] = arr[a++];
		}
	}

	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void PART(int*arr, int*arr2, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		PART(arr, arr2, left, mid);
		PART(arr, arr2, mid + 1, right);
		SORT(arr, arr2, left, mid, right);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	if (N > 1) {
		int*arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int*result = new int[N];
		PART(arr, result, 0, N - 1);

		for (int i = 0; i < N; i++) {
			cout << result[i] << "\n";
		}
	}
	else if (N == 1) { // N = 1일 때를 안 따져서 틀린 거였었음.
		int number;
		cin >> number;
		cout << number;
	}

	getchar();
	getchar();
	return 0;
}