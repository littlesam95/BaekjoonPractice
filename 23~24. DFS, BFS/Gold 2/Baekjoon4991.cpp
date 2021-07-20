#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int w, h;
int arr[25][25] = { 0, }; // ���� �� ����. ������ �ִ� ��ġ�� -1, �������� ������ �� �����Ƿ� 0
int dist[25][25]; // ��ǥ(y, x)���� �̵��� �Ÿ��� 2���� �迭�� ����
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

void init() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			dist[i][j] = 0;
		}
	}
}

void init2() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			arr[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	bool visited[25][25] = { false, };
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < h) && (next_x >= 0) && (next_x < w)) {
				if ((arr[next_y][next_x] != -1) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
					dist[next_y][next_x] = dist[now_y][now_x] + 1;
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> w >> h;
		if ((w == 0) && (h == 0)) { // (0, 0)�� �ԷµǾ��� ��� �ݺ��� ����
			break;
		}
		init2(); // �� �ʱ�ȭ
		int answer = MAX;
		vector<pair<int, int> > vec(1); // 1���� ���� �����ؼ� �κ� û�ұ��� ��ġ�� ������ 0��°�� ����. �� �������� ������ ĭ���� ��ġ ����
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char cmd;
				cin >> cmd;
				if (cmd == '*') {
					vec.push_back(make_pair(i, j));
				}
				else if (cmd == 'x') {
					arr[i][j] = -1;
				}
				else if (cmd == 'o') {
					vec[0] = make_pair(i, j);
				}
			}
		}
		int res[25][25] = { 0, }; // i�� ��ǥ���� j�� ��ǥ�� ���� �ִ� �Ÿ�
		for (int i = 0; i < vec.size(); i++) {
			init(); // �Ÿ� ���� 2���� �迭 �ʱ�ȭ
			bfs(vec[i].first, vec[i].second); // �κ� û�ұ� �� ������ ĭ�� ��ǥ�� ���������� bfs ����
			for (int j = 0; j < vec.size(); j++) {
				res[i][j] = dist[vec[j].first][vec[j].second];
			}
		}

		vector<int> loc(vec.size() - 1); // �κ� û�ұ��� ��ġ�� �� ������ ĭ���� ��ġ�� �ش��ϴ� �ε������� 1���� ���Ϳ� ����
		for (int i = 0; i < vec.size() - 1; i++) {
			loc[i] = i + 1;
		}
		answer = MAX;
		bool flag = true;

		do {
			int now_res = res[0][loc[0]]; // �κ� û�ұ⿡�� 1�� ������ ĭ������ �Ÿ�
			if (!now_res) { // �� 0�̸� �ٷ� �ݺ��� ���� : ������ ĭ�� �����ϰ� ���� �� ����
				flag = false;
				break;
			}
			for (int i = 1; i < vec.size() - 1; i++) {
				now_res += res[loc[i - 1]][loc[i]]; // 1�� ������ ĭ���� 2�� ������ ĭ������ �Ÿ� + ... + i - 1�� ������ ĭ���� i�� ������ ĭ������ �Ÿ�
			}
			answer = min(answer, now_res); // ���� �������� �Ÿ��� �հ� ������ �ʱ�ȭ���״� �Ÿ��� ���� ���� �� ���� ������ �ʱ�ȭ
		} while (next_permutation(loc.begin(), loc.end())); // next_permutation()�� �̿��Ͽ� ����� ���� �� �� �ִ� ��� 1���� ������ ������ �̿�

		if (!flag) {
			cout << -1 << "\n";
		}
		else {
			cout << answer << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}