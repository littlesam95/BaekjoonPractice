#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int money[1001];
int result = 0;

void calc(int* money, int order, int sum, int& result) {
	if (order == N) return;
	sum += money[order];
	result += sum;
	calc(money, order + 1, sum, result);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}
	sort(money, money + N);
	result += money[0];
	calc(money, 1, money[0], result);

	cout << result;

	getchar();
	getchar();
	return 0;
}