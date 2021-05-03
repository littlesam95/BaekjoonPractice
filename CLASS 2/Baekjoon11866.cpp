#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	if ((K < 1) || (K > N) || (N > 1000)) exit(0);
	deque<int> q;
	string cmd;

	int*arr = new int[N];

	for (int i = N; i >= K; i--) {
		q.push_front(i);
	}
	for (int i = 1; i < K; i++) {
		q.push_back(i);
	}

	for (int i = 0; i < N; i++) {
		if (i < (N - K + 1)) {
			arr[i] = q.front();
			q.pop_front();
			for (int i = 0; i < K - 1; i++) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			int order = K;
			while (order > q.size()) {
				order -= q.size();
			}
			for (int a = 0; a < order - 1; a++) {
				q.push_back(q.front());
				q.pop_front();
			}
			arr[i] = q.front();
			q.pop_front();
		}
	}

	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i < N - 1) {
			cout << arr[i] << ", ";
		}
		else if (i == N - 1) {
			cout << arr[i] << ">";
		}
	}

	getchar();
	getchar();
	return 0;
}