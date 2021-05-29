#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, s, e;

typedef struct {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
} comp;

priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q1;
priority_queue<int, vector<int>, greater<int> > q2;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		q1.push(make_pair(s, e));
	}

	while (!q1.empty()) {
		tie(s, e) = q1.top();
		q1.pop();

		if (q2.empty()) {
			q2.push(e);
		}
		else {
			if (s >= q2.top()) {
				q2.pop();
				q2.push(e);
			}
			else {
				q2.push(e);
			}
		}
	};

	cout << q2.size() << "\n";

	getchar();
	getchar();
	return 0;
}