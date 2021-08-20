#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 3001

using namespace std;
int T, N;
int arr[MAX];
int group_size;
vector<pair<pair<int, int>, pair<int, int> > > vec;

void init() {
	for (int i = 0; i < MAX; i++) {
		arr[i] = -1;
	}
	group_size = 0;
	vec.clear();
}

int find(int X) {
	if (arr[X] < 0) {
		return X;
	}
	int parent = find(arr[X]);
	arr[X] = parent;
	return parent;
}

void union_set(int X, int Y) {
	int P_X = find(X);
	int P_Y = find(Y);
	if (P_X != P_Y) {
		arr[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			vec.push_back(make_pair(make_pair(x, y), make_pair(r, i + 1)));
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int X = (vec[i].first.first - vec[j].first.first) * (vec[i].first.first - vec[j].first.first)
					+ (vec[i].first.second - vec[j].first.second) * (vec[i].first.second - vec[j].first.second);
				int Y = (vec[i].second.first + vec[j].second.first) * (vec[i].second.first + vec[j].second.first);
				if (X <= Y) {
					union_set(vec[i].second.second, vec[j].second.second);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			int parent = find(i);
			if (parent == i) {
				group_size++;
			}
		}
		cout << group_size << "\n";
	};

	getchar();
	getchar();
	return 0;
}