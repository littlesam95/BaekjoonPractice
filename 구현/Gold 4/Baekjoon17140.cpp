#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define INF 2e9

using namespace std;
int R, C, K;
int A[MAX][MAX];
int NumberCount[MAX];
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		NumberCount[i] = 0;
	}
}

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) {
		return (A.first < B.first);
	}
	return (A.second < B.second);
}

void Solve() {
	int Row = 3;
	int Col = 3;
	while (1) {
		if (A[R][C] == K) {
			break;
		}
		if (answer > 100) {
			answer = -1;
			break;
		}
		int big = 0;
		if (Row >= Col) {
			for (int i = 1; i <= Row; i++) {
				vector<pair<int, int> > vec;
				init();
				for (int j = 1; j <= Col; j++) {
					NumberCount[A[i][j]]++;
				}
				for (int j = 1; j < MAX; j++) {
					if (NumberCount[j] != 0) {
						vec.push_back(make_pair(j, NumberCount[j]));
					}
				}
				sort(vec.begin(), vec.end(), comp);
				for (int j = 1; j <= Col; j++) {
					A[i][j] = 0;
				}
				int Col_IDX = 1;
				for (int j = 0; j < vec.size(); j++) {
					A[i][Col_IDX++] = vec[j].first;
					A[i][Col_IDX++] = vec[j].second;
				}
				Col_IDX--;
				big = max(big, Col_IDX);
			}
			Col = big;
		}
		else {
			for (int i = 1; i <= Col; i++) {
				vector<pair<int, int> > vec;
				init();
				for (int j = 1; j <= Row; j++) {
					NumberCount[A[j][i]]++;
				}
				for (int j = 1; j < MAX; j++) {
					if (NumberCount[j] != 0) {
						vec.push_back(make_pair(j, NumberCount[j]));
					}
				}
				sort(vec.begin(), vec.end(), comp);
				for (int j = 1; j <= Row; j++) {
					A[j][i] = 0;
				}
				int Row_IDX = 1;
				for (int j = 0; j < vec.size(); j++) {
					A[Row_IDX++][i] = vec[j].first;
					A[Row_IDX++][i] = vec[j].second;
				}
				Row_IDX--;
				big = max(big, Row_IDX);
			}
			Row = big;
		}
		answer++;
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
	if (A[R][C] != K) {
		Solve();
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}