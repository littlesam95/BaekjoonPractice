#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Shark {
	int y, x, size, exp, dist;
};

struct Fish {
	int y, x, dist;
};

Shark S;
int N;
int arr[21][21];
bool visited[21][21];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<Fish> fish_vec;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void shark_fish_dist(int y, int x) { // 먹을 수 있는 물고기 찾기
	init();
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(y, x), 0)); // 일단 상어의 현재 위치 저장
	visited[y][x] = true;

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N) && (!visited[next_y][next_x])) {
				if (arr[next_y][next_x] == 0) { // 빈 칸이라면 지나갈 수 있다는 뜻이다.
					visited[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), now_dist + 1));
				}
				else if (arr[next_y][next_x] < S.size) { // 상어의 현재 크기보다 작다면 먹을 수 있다.
					Fish f;
					f.y = next_y;
					f.x = next_x;
					f.dist = now_dist + 1;
					fish_vec.push_back(f);
					visited[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), now_dist + 1));
				}
				else if (arr[next_y][next_x] == S.size) { // 상어의 현재 크가와 같다면 먹을 수는 없지만 지나갈 수는 있다.
					visited[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), now_dist + 1));
				}
			}
		}
	};
}

bool comp(Fish A, Fish B) {
	if (A.dist == B.dist) {
		if (A.y == B.y) {
			return (A.x < B.x);
		}
		else {
			return (A.y < B.y);
		}
	}
	else {
		return (A.dist < B.dist);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				S.y = i;
				S.x = j;
				S.size = 2;
				S.exp = 0;
				S.dist = 0;
			}
		}
	}
	while (1) {
		fish_vec.clear();
		shark_fish_dist(S.y, S.x);
		if (fish_vec.empty()) {
			break;
		}
		else if (fish_vec.size() == 1) {
			int now_y = fish_vec[0].y;
			int now_x = fish_vec[0].x;
			int now_dist = fish_vec[0].dist;
			arr[now_y][now_x] = 9;
			arr[S.y][S.x] = 0;
			S.y = now_y;
			S.x = now_x;
			S.exp++;
			if (S.size == S.exp) {
				S.size++;
				S.exp = 0;
			}
			S.dist += now_dist;
		}
		else {
			sort(fish_vec.begin(), fish_vec.end(), comp);
			int now_y = fish_vec[0].y;
			int now_x = fish_vec[0].x;
			int now_dist = fish_vec[0].dist;
			arr[now_y][now_x] = 9;
			arr[S.y][S.x] = 0;
			S.y = now_y;
			S.x = now_x;
			S.exp++;
			if (S.size == S.exp) {
				S.size++;
				S.exp = 0;
			}
			S.dist += now_dist;

		}
	}
	cout << S.dist << "\n";

	getchar();
	getchar();
	return 0;
}