#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int*arr = new int[T];
	int A, B;
	for (int i = 0; i < T; i++) {
		do {
			cin >> A >> B;
		} while ((A <= 0) || (A >= 10) || (B <= 0) || (B >= 10));
		arr[i] = A + B;
	}

	for (int i = 0; i < T; i++) {
		cout << arr[i] << "\n";
	}

	getchar();
	getchar();
	return 0;
}