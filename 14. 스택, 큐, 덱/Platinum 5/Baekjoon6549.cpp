#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100010

using namespace std;
int N;
long long H[MAX];
stack<int> s;
long long answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		H[i] = 0;
	}
	answer = 0;
	while (!s.empty()) {
		s.pop();
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N;
		if (N == 0) {
			break;
		}
		s.push(0);
		for (int i = 1; i <= N + 1; i++) {
			if (i <= N) {
				cin >> H[i];
			}
			if (s.top() == 0) {
				s.push(i);
			}
			else {
				if (H[s.top()] > H[i]) {
					while (H[s.top()] > H[i]) {
						int idx = s.top();
						s.pop();
						answer = max(answer, H[idx] * (i - s.top() - 1));
						if (s.top() == 0) {
							break;
						}
					};
				}
				s.push(i);
			}
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}