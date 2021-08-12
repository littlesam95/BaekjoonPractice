#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[50001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) { // 모든 수가 최대 4개의 제곱수로 나타낼 수 있으므로
		arr[i] = 4;
	}
	for (int i = 1; ( i* i) <= 50000; i++) { // 제곱수는 1개의 제곱수로 합을 나타낼 수 있으니 제곱수번째 배열마다 1로 초기화
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