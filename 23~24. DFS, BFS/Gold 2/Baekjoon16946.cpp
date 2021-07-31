#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
int arr[1000][1000];
int tmp[1000][1000];
int zero_count[1000000];
bool visited[1000][1000];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer[1000][1000];
int zero_num = 2;

void find_zero(int y, int x) {
	int size = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	tmp[y][x] = zero_num;

	while (!q.empty()) {
		size++;
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if ((!visited[next_y][next_x]) && (arr[next_y][next_x] == 0)) {
					visited[next_y][next_x] = true;
					tmp[next_y][next_x] = zero_num;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	};

	zero_count[zero_num] = size;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = stoi(tmp.substr(j, 1));
			if (arr[i][j]) {
				answer[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((arr[i][j] == 0) && (!visited[i][j])) {
				find_zero(i, j);
				zero_num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) {
				unordered_set<int> s;
				if ((i - 1 >= 0) && (!arr[i - 1][j])) {
					if (s.find(tmp[i - 1][j]) == s.end()) {
						answer[i][j] += zero_count[tmp[i - 1][j]];
						s.insert(tmp[i - 1][j]);
					}
				}
				if ((i + 1 < N) && (!arr[i + 1][j])) {
					if (s.find(tmp[i + 1][j]) == s.end()) {
						answer[i][j] += zero_count[tmp[i + 1][j]];
						s.insert(tmp[i + 1][j]);
					}
				}
				if ((j - 1 >= 0) && (!arr[i][j - 1])) {
					if (s.find(tmp[i][j - 1]) == s.end()) {
						answer[i][j] += zero_count[tmp[i][j - 1]];
						s.insert(tmp[i][j - 1]);
					}
				}
				if ((j + 1 < M) && (!arr[i][j + 1])) {
					if (s.find(tmp[i][j + 1]) == s.end()) {
						answer[i][j] += zero_count[tmp[i][j + 1]];
						s.insert(tmp[i][j + 1]);
					}
				}
				answer[i][j] %= 10;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << answer[i][j];
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}