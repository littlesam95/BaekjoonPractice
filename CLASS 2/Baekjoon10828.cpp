/*
	Baekjoon 10828 Ω∫≈√
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int order;
	string cmd;

	do {
		cin >> order;
	} while (order < 1 || order > 10000);

	int*q = new int[order];
	string*cmdArr = new string[order];
	int index = 0;
	int size = 0;
	int number;

	for (int i = 0; i < order; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, cmd);
		cmdArr[i] = cmd;
		cmd = "";
	}

	for (int i = 0; i < order; i++) {
		if (cmdArr[i].substr(0, 4) == "push") {
			number = stoi(cmdArr[i].substr(5));
			q[index] = number;
			index++;
			size++;
		}
		else if (cmdArr[i] == "pop") {
			if (size == 0) {
				cout << -1 << endl;
			}
			else {
				number = q[index - 1];
				size--;
				index--;
				cout << number << endl;
			}
		}
		else if (cmdArr[i] == "size") {
			cout << size << endl;
		}
		else if (cmdArr[i] == "empty") {
			if (size == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (cmdArr[i] == "top") {
			if (size == 0) {
				cout << -1 << endl;
			}
			else {
				cout << q[index - 1] << endl;
			}
		}
	}

	getchar();
	return 0;
}