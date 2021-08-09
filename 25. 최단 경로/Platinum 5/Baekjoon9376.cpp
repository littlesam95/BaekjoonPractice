#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int T, H, W;
char arr[101][101];
long long dist[3][101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
bool visited[101][101];
vector<pair<int, int> > prisoner;
priority_queue<pair<long long, pair<int, int> > > pq;
long long answer;

void init1() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			arr[i][j] = '.';
		}
	}
	prisoner.clear();
}

void init2(int idx) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
	for (int j = 0; j < 101; j++) {
		for (int k = 0; k < 101; k++) {
			dist[idx][j][k] = LLONG_MAX;
		}
	}
	while (!pq.empty()) {
		pq.pop();
	};
}

void dijkstra(int idx, int y, int x) {
	init2(idx); // 상근이 : 0, 죄수1 : 1, 죄수2 : 2
	pq.push(make_pair(0, make_pair(y, x)));
	dist[idx][y][x] = 0;

	while (!pq.empty()) {
		long long now_cost = -pq.top().first;
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		pq.pop();
		
		if (dist[idx][now_y][now_x] < now_cost) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			long long next_cost = dist[idx][now_y][now_x];
			if ((next_y >= 0) && (next_y <= H + 1) && (next_x >= 0) && (next_x <= W + 1) && (!visited[next_y][next_x])) { // 범위 안에 들어가있고 방문 X
				if (arr[next_y][next_x] == '*') { // 지나갈 수 없는 벽이면 무시
					continue;
				}
				if (arr[next_y][next_x] == '#') { // 문인 경우 연다.
					next_cost++;
				}
				if (dist[idx][next_y][next_x] > next_cost) {
					visited[now_y][now_x] = true;
					dist[idx][next_y][next_x] = next_cost;
					pq.push(make_pair(-dist[idx][next_y][next_x], make_pair(next_y, next_x)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init1(); // 땅을 전부 .으로 채운다.
		cin >> H >> W;
		prisoner.push_back(make_pair(0, 0)); // 상근이는 (0, 0)에서 출발
		for (int i = 1; i <= H; i++) {
			string S;
			cin >> S;
			for (int j = 1; j <= W; j++) {
				arr[i][j] = S[j - 1];
				if (arr[i][j] == '$') {
					prisoner.push_back(make_pair(i, j)); // 죄수들의 좌표 저장
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			dijkstra(i, prisoner[i].first, prisoner[i].second); // 상근이, 죄수1, 죄수2 순으로 다익스트라 실행
		}
		long long answer = LLONG_MAX;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (arr[i][j] != '*') {
					long long total = 0;
					for (int k = 0; k < 3; k++) {
						total += dist[k][i][j]; // 상근이와 죄수들이 열었던 문의 총합
					}
					total -= 2 * (arr[i][j] == '#'); // arr[i][j]이 문이라면 1, 아니면 0. 같은 문을 여러 사람들이 열었기 때문에 -2를 해준다.
					answer = min(answer, total);
				}
			}
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}