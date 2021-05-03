#include <iostream>

using namespace std;

int main() {

	int A, B;
	while (1) {
		cin >> A >> B;
		if (A != 0 || B != 0) {
			if ((A > 10) || (B > 10)) break;
			else {
				cout << A + B << endl;
			}
		}
		else break;
	}

	getchar();
	getchar();
	return 0;
}