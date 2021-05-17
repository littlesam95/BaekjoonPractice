#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[1000001] = { 0, };

void calc(int number) {
	if (number == 1) {
		arr[number] = 0; // 1은 원래부터 1이니 0번
	}
	else if (number >= 2) {
		arr[number] = arr[number - 1] + 1; // 우선 그 전 수의 최소 연산 + 1이라고 가정
		if (number % 2 == 0) { // 2로 나누어 떨어지면
			arr[number] = min(arr[number], arr[number / 2] + 1); // 2로 나눈 수의 연산 + 1과 비교해서 더 작은 값으로 설정
		}
		if (number % 3 == 0) { // 3으로 나누어 떨어지면
			arr[number] = min(arr[number], arr[number / 3] + 1); // 3으로 나눈 수의 연산 + 1과 비교해서 더 작은 값으로 설정
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