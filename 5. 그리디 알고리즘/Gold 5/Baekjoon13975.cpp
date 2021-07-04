#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int K;
		long long answer = 0;
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		for (int i = 0; i < K; i++) {
			int n;
			cin >> n;
			pq.push(n);
		}
		while (pq.size() > 1) {
			long long top1 = pq.top();
			pq.pop();
			long long top2 = pq.top();
			pq.pop();
			long long sum = top1 + top2;
			answer += sum;
			pq.push(sum);
		};

		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}