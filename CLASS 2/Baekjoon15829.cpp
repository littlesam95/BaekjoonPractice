#include <iostream>

#define MOD 1234567891

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	unsigned long long r = 31;
	unsigned long long L;
	do {
		cin >> L;
	} while ((L < 1) || (L > 50));
	char*arr = new char[L];
	for (int i = 0; i < L; i++) {
		cin >> arr[i];
		if ((int(arr[i]) < 97) || (int(arr[i]) > 122)) {
			exit(0);
		}
	}

	unsigned long long result = 0;
	unsigned long long number = 1;
	for (int i = 0; i < L; i++) {
		result += (int((arr[i]) - 96) * number) % MOD;
		number *= 31;
		number %= MOD;
	}

	cout << result % MOD;

	getchar();
	getchar();
	return 0;
}