#include <iostream>
#include <string>

using namespace std;

int main() {
	int N = 0;
	do {
		cin >> N;
	} while ((N < 1) || (N > 100));

	string str;
	cin.ignore();
	getline(cin, str);
	int len = str.length();
	if (len != N) {
		exit(0);
	}

	int sum = 0;
	int tmp;
	for (int i = 0; i < len; i++) {
		tmp = stoi(str.substr(i, 1));
		sum += tmp;
	}

	cout << sum;

	getchar();
	return 0;
}