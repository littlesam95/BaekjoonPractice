#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[1000001] = { 0, };

void calc(int number) {
	if (number == 1) {
		arr[number] = 0; // 1�� �������� 1�̴� 0��
	}
	else if (number >= 2) {
		arr[number] = arr[number - 1] + 1; // �켱 �� �� ���� �ּ� ���� + 1�̶�� ����
		if (number % 2 == 0) { // 2�� ������ ��������
			arr[number] = min(arr[number], arr[number / 2] + 1); // 2�� ���� ���� ���� + 1�� ���ؼ� �� ���� ������ ����
		}
		if (number % 3 == 0) { // 3���� ������ ��������
			arr[number] = min(arr[number], arr[number / 3] + 1); // 3���� ���� ���� ���� + 1�� ���ؼ� �� ���� ������ ����
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		calc(i);
	}

	cout << arr[N];
	getchar();
	getchar();
	return 0;
}