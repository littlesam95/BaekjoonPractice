#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> pq;
	int N;
	cin >> N;
	int x[100001];
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		if (x[i] == 0) {
			if (pq.size() > 0) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else if (pq.size() == 0) {
				cout << 0 << "\n";
			}
		}
		else if (x[i] > 0) {
			pq.push(x[i]);
		}
	}


	getchar();
	getchar();
	return 0;
}