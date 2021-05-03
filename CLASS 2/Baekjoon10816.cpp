#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

/* vector를 사용하면 vector 라이브러리 내부에 lower_bound, upper_bound 함수가 포함되어 있다.
   vector를 사용해서 하니 시간 초과가 되어 배열로 바꿔서 했더니 맞았다.
   vector를 사용한다고 하면 lower_bound, upper_bound 함수를 쓰면 더 간단해진다.

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

	sort(A.begin(), A.end()); // 가지고 있는 카드를 오름차순 정렬

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

// 이진 탐색 - 일치하는 원소의 첫 번째 위치(lower_bound)
int lowOrder(int*A, int number, int N) {
	int left = 0;
	int right = N - 1;
	int mid;

	while (right > left) { // 해당 카드번호와 일치하는 카드의 첫 번째 위치
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

// 이진 탐색 - 더 큰 원소의 첫 번째 위치(upper_bound)
int highOrder(int*A, int number, int N) {
	int left = 0;
	int right = N - 1;
	int mid;

	while (right > left) { // 해당 카드번호보다 큰 카드의 첫 번째 위치
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

	sort(A, A + N); // 가지고 있는 카드를 오름차순 정렬

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
