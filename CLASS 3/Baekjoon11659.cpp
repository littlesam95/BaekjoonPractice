#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
long long arr[100001];

// ���� ���� �̿�, j��° �� - (i - 1)��° ��
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr[0] = 0;
	int number;
	for (int i = 1; i <= N; i++) {
		cin >> number;
		arr[i] = arr[i - 1] + number; // ���� ��� ���Ѵ�.
	}

	int i, j;
	for (int count = 0; count < M; count++) {
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << "\n";
	}


	getchar();
	getchar();
	return 0;
}