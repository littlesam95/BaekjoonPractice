#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[1501][1501];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (q.size() < N) {
				q.push(arr[i][j]);
			}
			else if (q.size() == N) {
				if (arr[i][j] > q.top()) {
					q.pop();
					q.push(arr[i][j]);
				}
			}
		}
	}

	cout << q.top() << "\n";

	getchar();
	getchar();
	return 0;
}