#include <iostream>
#include <string>

using namespace std;

int main() {
	int score;
	do {
		cin >> score;
	} while ((score < 0) || (score > 100));

	if ((score == 100) || (score / 10 == 9)) {
		cout << "A";
	}
	else if (score / 10 == 8) {
		cout << "B";
	}
	else if (score / 10 == 7) {
		cout << "C";
	}
	else if (score / 10 == 6) {
		cout << "D";
	}
	else {
		cout << "F";
	}

	getchar();
	getchar();
	return 0;
}