#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int C, S, T;
int arr[251][251] = { 0, };
bool visited[251][251] = { false, };
int moveX[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int moveY[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int res;

void init() {
	res = 2147483647;
}

void bfs(int S, int T) {
	int count = 0;
	queue < pair<pair<int, int>, int > > q;
	q.push(make_pair(make_pair(S, T), count));

	while (!q.empty()) {
		int nowS = q.front().first.first;
		int nowT = q.front().first.second;
		int nowCount = q.front().second;
		q.pop();
		if (nowS == nowT) {
			if (res > nowCount) {
				res = nowCount;
			}
		}
		else if (nowS < nowT) {
			nowCount++;
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					int nextS = nowS + nowS;
					int nextT = nowT + 3;
					q.push(make_pair(make_pair(nextS, nextT), nowCount));
				}
				else if (i == 1) {
					int nextS = nowS + 1;
					int nextT = nowT;
					q.push(make_pair(make_pair(nextS, nextT), nowCount));
				}
			}
		}
		else {
			continue;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C;
	while (C--) {
		init();
		cin >> S >> T;
		bfs(S, T);
		cout << res << "\n";
	};

	getchar();
	getchar();
	return 0;
}