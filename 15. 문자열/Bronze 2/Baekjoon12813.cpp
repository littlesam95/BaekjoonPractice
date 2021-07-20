#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string A, B;

// 비트 연산을 알아보기 위한 문제

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A;
	cin >> B;

	// 1. A & B (AND 연산)
	string str1 = "";
	for (int i = 0; i < 100000; i++) {
		if ((A[i] == '1') && (A[i] == B[i])) {
			str1 += '1';
		}
		else {
			str1 += '0';
		}
	}
	cout << str1 << "\n";

	// 2. A | B (OR 연산)
	string str2 = "";
	for (int i = 0; i < 100000; i++) {
		if ((A[i] == '1') || (B[i] == '1')) {
			str2 += '1';
		}
		else {
			str2 += '0';
		}
	}
	cout << str2 << "\n";

	// 3. A ^ B (XOR 연산)
	string str3 = "";
	for (int i = 0; i < 100000; i++) {
		if (A[i] != B[i]) {
			str3 += '1';
		}
		else {
			str3 += '0';
		}
	}
	cout << str3 << "\n";

	// 4. ~A (NOT 연산)
	string str4 = "";
	for (int i = 0; i < 100000; i++) {
		if (A[i] == '1') {
			str4 += '0';
		}
		else {
			str4 += '1';
		}
	}
	cout << str4 << "\n";

	// 5. ~B (NOT 연산)
	string str5 = "";
	for (int i = 0; i < 100000; i++) {
		if (B[i] == '1') {
			str5 += '0';
		}
		else {
			str5 += '1';
		}
	}
	cout << str5 << "\n";

	getchar();
	getchar();
	return 0;
}