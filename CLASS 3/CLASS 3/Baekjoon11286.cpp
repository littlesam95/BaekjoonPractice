#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int N;
	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		if (number == 0) {
			if (pq.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(number), number));
		}
	}

	getchar();
	getchar();
	return 0;
}