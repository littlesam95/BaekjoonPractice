#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
int button[10] = { 1,1,1,1,1,1,1,1,1,1 };
int min_count = INT_MAX;

void comp(string num) {
	for (int i = 0; i < 10; i++) {
		if (button[i]) { // ��ư�� �������̶��
			string tmp = num + to_string(i);
			int tmpLen = tmp.length();
			min_count = min(min_count, abs(N - stoi(tmp)) + tmpLen); // +, - ��ư�� ���� �� ������ Ƚ�� vs ���� ����� ä�� ��ȣ�� ������ +, - ��ư�� ������ Ƚ��

			if (tmp.length() < 6) { // ��ǥ ä�� ��ȣ�� 6�ڸ����� �ƴ϶�� tmp���� �ٽ� �ݺ�(000001, 000002, 000003, ...)
				comp(tmp);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	min_count = min(min_count, abs(100 - N)); // N�� ���� ä�� ��ȣ�� 100�� ����
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		button[number] = 0;
	} // ���峭 ��ư�� 0

	if (M < 10) { // 0~9 ��ư�� ���� ���峵�ٸ� +, - ��ư�� ��� ������ �� �ۿ� ����
		comp("");
	}

	cout << min_count << "\n";

	getchar();
	getchar();
	return 0;
}