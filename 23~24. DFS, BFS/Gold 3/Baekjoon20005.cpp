#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x, dist;
};

struct Player {
	int id, dist;
};

struct comp {
	bool operator()(Player&A, Player&B) {
		return (A.dist > B.dist);
	}
};

int M, N, P;
char arr[1001][1001];
bool visited[1001][1001];
int boss_dist[26];
priority_queue<Player, vector<Player>, comp> pq;
int dps[26];
int boss_hp, boss_y, boss_x;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void init() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	init();
	queue<Info> q;
	visited[y][x] = true;
	q.push({ y,x,0 });

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_dist = q.front().dist;
		q.pop();

		if (arr[now_y][now_x] != '.') {
			int tmp = arr[now_y][now_x] - 'a';
			int tmp2 = now_dist;
			pq.push({ tmp,tmp2 });
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < M) && (next_x >= 0) && (next_x < N) && (!visited[next_y][next_x])) {
				if (arr[next_y][next_x] != 'X') {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x,now_dist + 1 });
				}
			}
		}
	};
}

void boss_hunt() {
	int sec = 0;
	int idx = 0;
	int damage_sum = 0;
	while (!pq.empty()) {
		while (!pq.empty()) {
			if (pq.top().dist <= sec) {
				int id = pq.top().id;
				damage_sum += dps[id];
				answer++;
				pq.pop();
			}
			else {
				break;
			}
		}
		sec++;
		boss_hp -= damage_sum;
		if (boss_hp <= 0) {
			break;
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> P;
	for (int i = 0; i < M; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'B') {
				arr[i][j] = '.';
				boss_y = i;
				boss_x = j;
			}
		}
	}
	for (int i = 0; i < P; i++) {
		char player;
		int damage;
		cin >> player >> damage;
		dps[player - 'a'] = damage;
	}
	cin >> boss_hp;
	bfs(boss_y, boss_x);
	boss_hunt();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}