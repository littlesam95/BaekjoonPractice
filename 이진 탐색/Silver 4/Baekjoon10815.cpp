#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, M;
int card[500001];
bool res[500001];

bool calc(int left, int right, int number) {
	bool b = false;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] > number) {
			right = mid - 1;
		}
		else if (card[mid] < number) {
			left = mid + 1;
		}
		else {
			b = true;
			break;
		}
	};
	return b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card, card + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		res[i] = calc(0, N - 1, number);
	}

	for (int i = 0; i < M; i++) {
		cout << res[i] << " ";
	}

	getchar();
	getchar();
	return 0;
}