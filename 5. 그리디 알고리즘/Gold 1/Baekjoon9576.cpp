#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) {
		return (A.first < B.first);
	}
	else {
		return (A.second < B.second);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int N, M;
		vector<pair<int, int> > vec;
		int book[1001] = { false, };
		int answer = 0;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			vec.push_back(make_pair(n1, n2));
		}
		sort(vec.begin(), vec.end(), comp);

		for (int i = 0; i < M; i++) {
			int start = vec[i].first;
			int end = vec[i].second;
			for (int j = start; j <= end; j++) {
				if (!book[j]) {
					book[j] = true;
					answer++;
					break;
				}
			}
		}

		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}

// 골드1 맞냐?
