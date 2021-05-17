#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T;
int arr[11];

// �Ǻ���ġ �������� Ȯ�� �����ϴ�.
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 10; i++) {
		if (i == 1) {
			arr[i] = 1;
		}
		else if (i == 2) {
			arr[i] = 2;
		}
		else if (i == 3) {
			arr[i] = 4;
		}
		else {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
	}

	int N; // 1 ~ 10�� ���
	cin >> T;
	for (int number = 0; number < T; number++) {
		cin >> N;
		cout << arr[N] << "\n";
	}

	getchar();
	getchar();
	return 0;
}