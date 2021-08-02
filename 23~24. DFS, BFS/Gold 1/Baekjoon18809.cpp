#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x;
};

int N, M, G, R;
int arr[51][51];
int tmp[51][51];
bool visited[51][51];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<pair<int, int> > vec;
vector<int> grand;
vector<int> color;
int answer = INT_MIN;

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = false;
			tmp[i][j] = arr[i][j];
		}
	}
}

void bfs() {
	vector<pair<int, int> > land; // ������ �Ѹ� �� ���ϱ�
	for (int i = 0; i < grand.size(); i++) {
		if (grand[i] == 1) {
			land.push_back(vec[i]); // ������ �Ѹ� ��(1)�̶�� land ���Ϳ� ����
		}
	}

	do {
		int flower = 0;
		queue<Info> q;
		for (int i = 0; i < land.size(); i++) {
			tmp[land[i].first][land[i].second] = color[i]; // next_permutation()�� ���Ͽ� ������ �Ѹ��� ������ ���ϰ� ������ �Ѹ���.(3 �ƴϸ� 4)
			visited[land[i].first][land[i].second] = true;
			q.push({ land[i].first,land[i].second }); // ������ ��Ʈ���� ���� queue�� ����
		}

		while (1) {
			vector<Info> now; // ���� �ѷ��� �ʷϻ� Ȥ�� ������ ������ ��ġ
			bool flag = false;

			while (!q.empty()) {
				int now_y = q.front().y;
				int now_x = q.front().x;
				q.pop();

				int now_color = tmp[now_y][now_x];
				for (int i = 0; i < 4; i++) {
					int next_y = now_y + moveY[i];
					int next_x = now_x + moveX[i];
					if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
						if ((tmp[next_y][next_x] > 0) && (tmp[next_y][next_x] < 7) && (!visited[next_y][next_x])) {
							if (((tmp[now_y][now_x] == 4) && (tmp[next_y][next_x] == 5)) ||
								((tmp[now_y][now_x] == 3) && (tmp[next_y][next_x] == 6))) {
								tmp[next_y][next_x] = 7;
								flower++;
							}
							else {
								flag = true;
								tmp[next_y][next_x] = tmp[now_y][now_x] + 2;
								now.push_back({ next_y,next_x });
							}
						}
					}
				}
			};

			if (!flag) {
				answer = max(answer, flower); // �� ����
				break;
			}

			for (int k = 0; k < now.size(); k++) {
				visited[now[k].y][now[k].x] = true;

				if (tmp[now[k].y][now[k].x] != 7 && (tmp[now[k].y][now[k].x] == 5 || tmp[now[k].y][now[k].x] == 6)) {
					tmp[now[k].y][now[k].x] = tmp[now[k].y][now[k].x] - 2;
					q.push({ now[k].y,now[k].x });
				}
			}
		};
		init();
	} while (next_permutation(color.begin(), color.end()));
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				vec.push_back(make_pair(i, j)); // ������ �Ѹ� �� �ִ� ���� ��ǥ ����
			}
		}
	}
	for (int i = 0; i < R + G; i++) {
		grand.push_back(1); // ������ �Ѹ��� ���(1)
	}
	for (int i = 0; i < vec.size() - (R + G); i++) {
		grand.push_back(0); // (������ �Ѹ� �� �ִ� �� - ������ �� ����)��ŭ�� �������� ���� X
	}
	sort(grand.begin(), grand.end()); // next_permutation() �Լ� ����� ���� ����
	for (int i = 0; i < G; i++) {
		color.push_back(3); // �ʷϻ� ������ 3���� ����
	}
	for (int i = 0; i < R; i++) {
		color.push_back(4); // ������ ������ 4�� ����
	}
	sort(color.begin(), color.end()); // next_permutation() �Լ� ����� ���� ����
	do {
		init();
		bfs(); // BFS ����
	} while (next_permutation(grand.begin(), grand.end())); // ������ ����� �Ѹ� ������ next_permutation() �Լ��� ���Ͽ� ����
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}