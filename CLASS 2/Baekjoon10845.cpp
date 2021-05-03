#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	if ((N < 1) || (N > 10000)) exit(0);
	queue<int> q;
	string cmd;
	int arr[10000];
	int index = 0;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, cmd);
		if (cmd.substr(0, 4) == "push") {
			int number = stoi(cmd.substr(5));
			if ((number >= 1) && (number <= 100000)) {
				q.push(number);
			}
			else {
				exit(0);
			}
		}
		else if (cmd == "pop") {
			if (q.size() > 0) {
				arr[index++] = q.front();
				q.pop();
			}
			else if (q.size() == 0) {
				arr[index++] = -1;
			}
		}
		else if (cmd == "size") {
			arr[index++] = q.size();
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				arr[index++] = 1;
			}
			else if (!q.empty()) {
				arr[index++] = 0;
			}
		}
		else if (cmd == "front") {
			if (q.size() > 0) {
				arr[index++] = q.front();
			}
			else if (q.size() == 0) {
				arr[index++] = -1;
			}
		}
		else if (cmd == "back") {
			if (q.size() > 0) {
				arr[index++] = q.back();
			}
			else if (q.size() == 0) {
				arr[index++] = -1;
			}
		}
		else {
			exit(0);
		}
	}

	for (int i = 0; i < index; i++) {
		cout << arr[i] << "\n";
	}

	getchar();
	getchar();
	return 0;
}