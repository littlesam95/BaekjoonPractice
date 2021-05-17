#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int M;
	cin >> M;
	int n = 20;
	int s = 0;
	for (int i = 0; i < M; i++) {
		if (i == 0) {
			cin.ignore();
		}
		string cmd;
		getline(cin, cmd);
		if (cmd.substr(0, 3) == "add") { // 집합에 원소 추가
			int number = stoi(cmd.substr(4));
			number--;
			s = (s | (1 << number));
		}
		else if (cmd.substr(0, 6) == "remove") { // 집합에서 원소 제거
			int number = stoi(cmd.substr(7));

			number--;
			s = (s & ~(1 << number));
		}
		else if (cmd.substr(0, 5) == "check") { // 집합에서 원소 찾기
			int number = stoi(cmd.substr(6));
			number--;
			int ans = (s & (1 << number));
			if (ans) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (cmd.substr(0, 6) == "toggle") { // 집합에서 원소 있으면 제거, 없으면 추가
			int number = stoi(cmd.substr(7));
			number--;
			s = (s ^ (1 << number));
		}
		else if (cmd == "all") { // 집합을 {1, 2, .., 20}으로 바꿈
			s = (s | (1 << n) - 1);
		}
		else if (cmd == "empty") { // 집합을 공집합으로 바꿈
			s = 0;
		}
	}

	getchar();
	getchar();
	return 0;
}