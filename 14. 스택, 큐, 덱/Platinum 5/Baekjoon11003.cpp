#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 21

using namespace std;
int N, L;
deque<pair<int, int> > dq;
vector<int> answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		if (dq.empty()) {
			dq.push_back(make_pair(X, i));
			answer.push_back(X);
		}
		else {
			if (dq.front().second < i - L + 1) {
				dq.pop_front();
			}
			while (!dq.empty()) {
				if (dq.back().first > X) {
					dq.pop_back();
				}
				else {
					break;
				}
			};
			dq.push_back(make_pair(X, i));
			answer.push_back(dq.front().first);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	getchar();
	getchar();
	return 0;
}