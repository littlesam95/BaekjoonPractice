#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int N;

// 10의 배수를 세면 되는데, 2는 어차피 5보다 많으므로 그냥 5의 배수만 세면 된다.
void calc(int N, int& count) {
	for (int i = 2; i <= N; i++) {
		if ((i % 5 == 0) && (i % 25 != 0)) {
			count++;
		}
		else if ((i % 25 == 0) && (i % 125 != 0)) {
			count += 2;
		}
		else if ((i % 125 == 0)) {
			count += 3;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int count = 0;

	cin >> N;
	calc(N, count);
	cout << count;

	getchar();
	getchar();
	return 0;
}