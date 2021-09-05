#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 80001

using namespace std;
int N;
int top = 0;
int arr[MAX];
stack<pair<int, int> > s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		top = max(top, arr[i]);
	}
	s.push(make_pair(top + 1, N));
	for (int i = N - 1; i >= 0; i--) {
		if (s.empty()) {
			s.push(make_pair(arr[i], i));
		}
		else {
			while (!s.empty()) {
				if (s.top().first >= arr[i]) {
					answer += s.top().second - i - 1;
					break;
				}
				s.pop();
				if (s.empty()) {
					break;
				}
			};
			s.push(make_pair(arr[i], i));
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}