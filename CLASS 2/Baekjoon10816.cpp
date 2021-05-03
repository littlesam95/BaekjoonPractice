#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

/* vector�� ����ϸ� vector ���̺귯�� ���ο� lower_bound, upper_bound �Լ��� ���ԵǾ� �ִ�.
   vector�� ����ؼ� �ϴ� �ð� �ʰ��� �Ǿ� �迭�� �ٲ㼭 �ߴ��� �¾Ҵ�.
   vector�� ����Ѵٰ� �ϸ� lower_bound, upper_bound �Լ��� ���� �� ����������.

int N, M;
vector<int> A;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		A.push_back(number);
	}

	sort(A.begin(), A.end()); // ������ �ִ� ī�带 �������� ����

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> number;
		cout << upper_bound(A.begin(), A.end(), number) - lower_bound(A.begin(), A.end(), number) << " ";
	}

	getchar();
	getchar();
	return 0;
}
*/

int N, M;
int A[500001];
int B[500001];

// ���� Ž�� - ��ġ�ϴ� ������ ù ��° ��ġ(lower_bound)
int lowOrder(int*A, int number, int N) {
	int left = 0;
	int right = N - 1;
	int mid;

	while (right > left) { // �ش� ī���ȣ�� ��ġ�ϴ� ī���� ù ��° ��ġ
		mid = (left + right) / 2;
		if (A[mid] >= number) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	};
	return right;
}

// ���� Ž�� - �� ū ������ ù ��° ��ġ(upper_bound)
int highOrder(int*A, int number, int N) {
	int left = 0;
	int right = N - 1;
	int mid;

	while (right > left) { // �ش� ī���ȣ���� ū ī���� ù ��° ��ġ
		mid = (left + right) / 2;
		if (A[mid] > number) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	};
	return right;
}

// upper_bound - lower_bound
int countCard(int*A, int number, int N) {
	int low = lowOrder(A, number, N);
	int high = highOrder(A, number, N);

	int result = high - low;
	if (A[N - 1] == number) {
		result++;
	}

	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		A[i] = number;
	}

	sort(A, A + N); // ������ �ִ� ī�带 �������� ����

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> number;
		B[i] = number;
	}
	for (int i = 0; i < M; i++) {
		cout << countCard(A, B[i], N) << " ";
	}

	getchar();
	getchar();
	return 0;
}
