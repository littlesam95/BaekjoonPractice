#include <iostream>

using namespace std;

// 유클리드 호제법 사용!
int GCD(int A, int B) {
	while (B != 0) {
		int tmp = A % B;
		A = B;
		B = tmp;
	}
	return A;
}

int LCM(int A, int B, int C) {
	return (A * B) / C;
}

int main() {
	int A, B;
	do {
		cin >> A >> B;
	} while ((A < 1) || (A > 10000) || (B < 1) || (B > 10000));

	int G = GCD(A, B);
	int L = LCM(A, B, G);

	cout << G << endl;
	cout << L;

	/*
	int result1;
	int result2 = 1;
	int arr1[10000] = { 0, };
	int arr2[10000] = { 0, };
	int len = (A[0] > A[1]) ? A[1] : A[0];

	if (A[0] == A[1]) {
		cout << A[0] << endl;
		cout << A[0];
	}
	else {
		if ((A[0] > 1) && (A[1] > 1)) {
			for (int i = len; i >= 2; i--) {
				if ((A[0] % i == 0) && (A[1] % i == 0)) {
					result1 = i;
					break;
				}
			}


			int K;
			len = (A[0] > A[1]) ? A[0] : A[1];
			for (int a = 0; a < 2; a++) {
				K = 2;
				if (a == 0) {
					do {
						A[a] /= K;
						arr1[K]++;
						if (A[a] % K != 0) {
							K++;
						}
					} while (A[a] > 1);
				}
				else {
					do {
						A[a] /= K;
						arr2[K]++;
						if (A[a] % K != 0) {
							K++;
						}
					} while (A[a] > 1);
				}
			}

			int arr[10000] = { 0, };
			for (int i = 2; i < len; i++) {
				if (arr1[i] > arr2[i]) {
					arr[i] = arr1[i];
				}
				else {
					arr[i] = arr2[i];
				}
				if (arr[i] != 0) {
					result2 *= pow(i, arr[i]);
				}
			}

			cout << result1 << endl;
			cout << result2 << endl;
		}
		else if ((A[0] == 1) && (A[1] > 1)) {
			cout << 1 << endl;
			cout << A[1];
		}
		else if ((A[1] == 1) && (A[0] > 1)) {
			cout << 1 << endl;
			cout << A[0];
		}
	}
	*/

	getchar();
	getchar();
	return 0;
}