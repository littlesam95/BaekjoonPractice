#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	string*str = new string[T];
	int len;
	for (int i = 0; i < T; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, str[i]);
		len = str[i].length();
		for (int j = 0; j < len; j++) {
			if ((str[i].substr(j, 1) != "O") || (str[i].substr(j, 1) != "X")) {
				break;
			}
		}
	}

	int sum, score;
	for (int i = 0; i < T; i++) {
		score = 0;
		sum = 0;
		len = str[i].length();
		for (int j = 0; j < len; j++) {
			if (str[i].substr(j, 1) == "O") {
				score++;
				sum += score;
			}
			else if (str[i].substr(j, 1) == "X") {
				score = 0;
			}
		}
		cout << sum << endl;
	}

	getchar();
	getchar();
	return 0;
}