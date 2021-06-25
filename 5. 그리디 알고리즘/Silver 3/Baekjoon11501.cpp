#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
int T, N;

struct comp {
	bool operator()(pair<int, int>&A, pair<int, int>&B) {
		if (A.first < B.first) {
			return true;
		}
		else if (A.first == B.first) {
			return (A.second > B.second);
		}
		else {
			return false;
		}
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	int big;
	while (T--) {
		cin >> N;
		priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
		long long answer = 0;
		vector<int> jusik;
		for (int i = 0; i < N; i++) {
			int number;
			cin >> number;
			jusik.push_back(number);
			pq.push(make_pair(number, i));
		}

		int big = pq.top().first;
		int idx = 0;
		int start = 0;
		int end = 0;
		while (idx < jusik.size()) {
			if (jusik[idx] == big) {
				end = idx - 1;
				for (int i = start; i <= end; i++) {
					answer += (jusik[idx] - jusik[i]);
				}
				pq.pop();
				while (!pq.empty()) {
					if (pq.top().second < idx) {
						pq.pop();
					}
					else {
						big = pq.top().first;
						break;
					}
				};
				start = idx + 1;
			}
			idx++;
		};
		while (!pq.empty()) {
			pq.pop();
		};
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}