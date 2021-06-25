#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int answer = 0;
		vector<int> tree;
		for (int i = 0; i < N; i++) {
			int number;
			cin >> number;
			tree.push_back(number);
		}
		sort(tree.begin(), tree.end());

		int count_set = (N / 2);
		int arr[10000] = { 0, };
		int idx = tree.size() - 1;
		if (N % 2 == 0) {
			int mid = (N / 2) - 1;
			for (int i = 0; i < count_set; i++) {
				arr[mid - i] = tree[idx--];
				arr[mid + 1 + i] = tree[idx--];
			}
		}
		else if (N % 2 == 1) {
			int mid = (N / 2);
			arr[mid] = tree[idx--];
			for (int i = 1; i <= count_set; i++) {
				arr[mid - i] = tree[idx--];
				arr[mid + i] = tree[idx--];
			}
		}
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				answer = max(answer, abs(arr[i] - arr[0]));
			}
			else {
				answer = max(answer, abs(arr[i] - arr[i + 1]));
			}
		}

		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}