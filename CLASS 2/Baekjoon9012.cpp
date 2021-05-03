#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	int count;
	string*PS = new string[T];
	int*VPS = new int[50];

	for (int i = 0; i < T; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, PS[i]);
		if (PS[i].length() < 2 || PS[i].length() > 50) {
			cout << "���ڿ��� ���̰� 2 �̻� 50 ���ϰ� �ƴմϴ�." << endl;
			break;
		}
	}

	for (int i = 0; i < T; i++) {
		count = 0;
		VPS[0] = { 0, };
		for (int j = 0; j < PS[i].length(); j++) {
			if (count > 0) {
				if (PS[i].substr(j, 1) == "(") {
					VPS[count++] = count;
				}
				else if (PS[i].substr(j, 1) == ")") {
					VPS[count--] = 0;
				}
			}
			else if (count <= 0) {
				if (PS[i].substr(j, 1) == "(") {
					VPS[count++] = count;
				}
				else if (PS[i].substr(j, 1) == ")") {
					count--;
					break;
				}
			}
		}
		if (count == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	getchar();
	return 0;
}