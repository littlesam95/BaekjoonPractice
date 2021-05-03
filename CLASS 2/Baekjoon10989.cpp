#include <iostream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int number;
	int arr[10001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> number;
		arr[number]++;
	}

	int order;
	for (int i = 1; i < 10001; i++) {
		order = arr[i];
		if (order > 0) {
			for (int j = 0; j < order; j++) {
				cout << i << "\n";
			}
		}
	}

	getchar();
	getchar();
	return 0;
}