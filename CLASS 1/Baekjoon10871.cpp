#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X;
	do {
		cin >> N >> X;
	} while ((N < 1) || (X > 100000));

	int*arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if ((arr[i] < 1) || (arr[i] > 10000)) {
			exit(0);
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (X < arr[i]) {
			count++;
		}
	}

	if (count == N) {
		exit(0);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i < N - 1) {
				if (arr[i] < X) {
					cout << arr[i] << " ";
				}
			}
			else if (i == N - 1) {
				if (arr[i] < X) {
					cout << arr[i];
				}

			}
		}
	}

	getchar();
	getchar();
	return 0;
}