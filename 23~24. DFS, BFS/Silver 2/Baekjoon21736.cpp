#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
char arr[601][601];
bool visited[601][601] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

void bfs(int y, int x, int&person) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newY = nowY + moveY[i];
			int newX = nowX + moveX[i];
			if ((newY >= 0) && (newY < N) && (newX >= 0) && (newX < M)) {
				if ((!visited[newY][newX]) && (arr[newY][newX] != 'X')) {
					visited[newY][newX] = true;
					q.push(make_pair(newY, newX));
					if (arr[newY][newX] == 'P') {
						person++;
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int person = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 'I')) {
				bfs(i, j, person);
			}
		}
	}

	if (person == 0) {
		cout << "TT" << "\n";
	}
	else {
		cout << person << "\n";
	}


	getchar();
	getchar();
	return 0;
}