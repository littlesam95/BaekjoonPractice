#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	do {
		cin >> N;
	} while ((N < 1) || (N > 1000000));

	int*arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if ((arr[i] < -1000000) || (arr[i] > 1000000)) {
			exit(0);
		}
	}

	int big = arr[0];
	int small = arr[0];
	for (int i = 1; i < N; i++) {
		if (big < arr[i]) {
			big = arr[i];
		}
		if (small > arr[i]) {
			small = arr[i];
		}
	}

	cout << small << " " << big;

	getchar();
	getchar();
	return 0;
}