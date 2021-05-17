#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[301];
int result[301];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	result[0] = arr[0];
	result[1] = max(arr[0] + arr[1], arr[1]);
	result[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	// 3��° ��ܺ��ʹ�
	for (int i = 3; i < N; i++) {
		result[i] = max(result[i - 2] + arr[i], result[i - 3] + arr[i - 1] + arr[i]);
		// 1. N - 2��° ����� ��Ҵٸ�, ������ ����� ������ �ջ��ϸ� �ȴ�.
		// 2. N - 3��° ����� ��Ҵٸ�, N - 1��° ����� ��� N��° ����� ��ƾ� ��Ģ�� ��߳��� �ʴ´�.
		// �� ������ ��� �� �ִ��� ������.
	}

	cout << result[N - 1];

	getchar();
	getchar();
	return 0;
}