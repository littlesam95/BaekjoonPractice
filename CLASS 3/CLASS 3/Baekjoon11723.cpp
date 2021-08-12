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
		if (cmd.substr(0, 3) == "add") { // ���տ� ���� �߰�
			int number = stoi(cmd.substr(4));
			number--;
			s = (s | (1 << number));
		}
		else if (cmd.substr(0, 6) == "remove") { // ���տ��� ���� ����
			int number = stoi(cmd.substr(7));

			number--;
			s = (s & ~(1 << number));
		}
		else if (cmd.substr(0, 5) == "check") { // ���տ��� ���� ã��
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
		else if (cmd.substr(0, 6) == "toggle") { // ���տ��� ���� ������ ����, ������ �߰�
			int number = stoi(cmd.substr(7));
			number--;
			s = (s ^ (1 << number));
		}
		else if (cmd == "all") { // ������ {1, 2, .., 20}���� �ٲ�
			s = (s | (1 << n) - 1);
		}
		else if (cmd == "empty") { // ������ ���������� �ٲ�
			s = 0;
		}
	}

	getchar();
	getchar();
	return 0;
}