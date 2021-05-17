#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
unsigned long long N;
unsigned long long arr[1001];

// �� ������ �Ǻ���ġ �������� �� �� ����. ���� Ŀ���� ������ �ڷ����� �ٲ���.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 1000; i++) {
		if (i == 1) {
			arr[i] = 1;
		}
		else if (i == 2) {
			arr[i] = 2;
		}
		else if (i >= 3) {
			arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
		}
	}

	cin >> N;
	cout << arr[N];

	getchar();
	getchar();
	return 0;
}