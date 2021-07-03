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
		unsigned long long answer = 1;
		priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > pq;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			unsigned long long n;
			cin >> n;
			pq.push(n);
		}
		while (pq.size() > 1) {
			unsigned long long top1 = pq.top();
			pq.pop();
			unsigned long long top2 = pq.top();
			pq.pop();
			unsigned long long mul = top1 * top2;
			answer *= (mul % 1000000007);
			answer %= 1000000007;
			pq.push(mul);
		};

		cout << (answer % 1000000007) << "\n";
	};

	getchar();
	getchar();
	return 0;
}