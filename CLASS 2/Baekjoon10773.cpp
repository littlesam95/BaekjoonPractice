#include <iostream>

using namespace std;

int main() {
	int K = 0;

	do {
		cin >> K;
	} while (K < 1 || K > 100000);

	int*arr = new int[K];
	int number;
	int index = 0;

	for (int i = 0; i < K; i++) {
		cin >> number;
		if (number > 0) {
			arr[index++] = number;
		}
		else if (number == 0) {
			arr[index--] = 0;
		}
		else if (number < 0 || number > 1000000) {
			break;
		}
	}

	int sum = 0;

	for (int i = 0; i < index; i++) {
		sum += arr[i];
	}
	cout << sum;

	getchar();
	getchar();
	return 0;
}