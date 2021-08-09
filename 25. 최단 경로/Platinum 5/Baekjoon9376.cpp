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
	init2(idx); // ����� : 0, �˼�1 : 1, �˼�2 : 2
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
			if ((next_y >= 0) && (next_y <= H + 1) && (next_x >= 0) && (next_x <= W + 1) && (!visited[next_y][next_x])) { // ���� �ȿ� ���ְ� �湮 X
				if (arr[next_y][next_x] == '*') { // ������ �� ���� ���̸� ����
					continue;
				}
				if (arr[next_y][next_x] == '#') { // ���� ��� ����.
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
		init1(); // ���� ���� .���� ä���.
		cin >> H >> W;
		prisoner.push_back(make_pair(0, 0)); // ����̴� (0, 0)���� ���
		for (int i = 1; i <= H; i++) {
			string S;
			cin >> S;
			for (int j = 1; j <= W; j++) {
				arr[i][j] = S[j - 1];
				if (arr[i][j] == '$') {
					prisoner.push_back(make_pair(i, j)); // �˼����� ��ǥ ����
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			dijkstra(i, prisoner[i].first, prisoner[i].second); // �����, �˼�1, �˼�2 ������ ���ͽ�Ʈ�� ����
		}
		long long answer = LLONG_MAX;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (arr[i][j] != '*') {
					long long total = 0;
					for (int k = 0; k < 3; k++) {
						total += dist[k][i][j]; // ����̿� �˼����� ������ ���� ����
					}
					total -= 2 * (arr[i][j] == '#'); // arr[i][j]�� ���̶�� 1, �ƴϸ� 0. ���� ���� ���� ������� ������ ������ -2�� ���ش�.
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