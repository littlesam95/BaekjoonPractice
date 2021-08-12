#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
unsigned long long N;
unsigned long long arr[1001];

// 잘 세보면 피보나치 수열임을 알 수 있음. 수가 커지기 때문에 자료형을 바꿨음.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	arr[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (i % 2 == 0) {
			arr[i] = (arr[i - 1] * 2 + 1) % 10007;
		}
		else if (i % 2 == 1) {
			arr[i] = (arr[i - 1] * 2 - 1) % 10007;
		}
	}

	cin >> N;
	cout << arr[N];

	getchar();
	getchar();
	return 0;
}