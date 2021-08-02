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
	vector<pair<int, int> > land; // 배양액을 뿌릴 땅 정하기
	for (int i = 0; i < grand.size(); i++) {
		if (grand[i] == 1) {
			land.push_back(vec[i]); // 배양액을 뿌릴 땅(1)이라면 land 벡터에 저장
		}
	}

	do {
		int flower = 0;
		queue<Info> q;
		for (int i = 0; i < land.size(); i++) {
			tmp[land[i].first][land[i].second] = color[i]; // next_permutation()을 통하여 배양액을 뿌리는 순서를 정하고 배양액을 뿌린다.(3 아니면 4)
			visited[land[i].first][land[i].second] = true;
			q.push({ land[i].first,land[i].second }); // 배양액을 퍼트리기 위해 queue에 저장
		}

		while (1) {
			vector<Info> now; // 지금 뿌려질 초록색 혹은 빨간색 배양액의 위치
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
				answer = max(answer, flower); // 값 갱신
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
				vec.push_back(make_pair(i, j)); // 배양액을 뿌릴 수 있는 땅의 좌표 저장
			}
		}
	}
	for (int i = 0; i < R + G; i++) {
		grand.push_back(1); // 배양액을 뿌리는 경우(1)
	}
	for (int i = 0; i < vec.size() - (R + G); i++) {
		grand.push_back(0); // (배양액을 뿌릴 수 있는 땅 - 배양액의 총 개수)만큼의 땅에서는 배양액 X
	}
	sort(grand.begin(), grand.end()); // next_permutation() 함수 사용을 위한 정렬
	for (int i = 0; i < G; i++) {
		color.push_back(3); // 초록색 배양액은 3으로 저장
	}
	for (int i = 0; i < R; i++) {
		color.push_back(4); // 빨간색 배양액은 4로 저장
	}
	sort(color.begin(), color.end()); // next_permutation() 함수 사용을 위한 정렬
	do {
		init();
		bfs(); // BFS 시작
	} while (next_permutation(grand.begin(), grand.end())); // 배양액을 어디어디에 뿌릴 건지를 next_permutation() 함수를 통하여 결정
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}