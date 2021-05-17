#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[50001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) { // ��� ���� �ִ� 4���� �������� ��Ÿ�� �� �����Ƿ�
		arr[i] = 4;
	}
	for (int i = 1; ( i* i) <= 50000; i++) { // �������� 1���� �������� ���� ��Ÿ�� �� ������ ��������° �迭���� 1�� �ʱ�ȭ
		arr[i * i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; i - (j * j) > 0; j++) {
			arr[i] = min(arr[i], arr[i - (j * j)] + arr[j * j]);
		}
	}

	cout << arr[N];

	getchar();
	getchar();
	return 0;
}