#include <iostream>

using namespace std;

int main() {
	char ch;
	cin >> ch;

	if ((int(ch) >= 48) && (int(ch) <= 57) || (int(ch) >= 65) && (int(ch) <= 90) || (int(ch) >= 97) && (int(ch) <= 122)) {
		cout << int(ch);
	}
	else exit(0);

	getchar();
	getchar();
	return 0;
}