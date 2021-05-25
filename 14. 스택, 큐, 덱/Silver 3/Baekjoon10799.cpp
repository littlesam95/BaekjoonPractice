#include <iostream>
#include <string>

using namespace std;

int main() {
	string K;
	cin >> K;

	int*number = new int[100000];
	int index = 0;
	int count = 0;

	// (( : ���� 1�� PUSH, () : ��ü ���� �ڸ�, )) : ���� �ϳ� POP

	for (int i = 0; i < K.length(); i++) {
		if (K.substr(i, 1) == "(" && K.substr(i + 1, 1) == "(") {
			number[index++] = 1;
		}
		else if (K.substr(i, 1) == "(" && K.substr(i + 1, 1) == ")") {
			for (int i = 0; i < index; i++) {
				number[i] += 1;
			}
		}
		else if (K.substr(i, 1) == ")" && K.substr(i + 1, 1) == ")") {
			count += number[index - 1];
			number[index--] = 0;
		}
	}

	cout << count;


	getchar();
	getchar();
	return 0;
}