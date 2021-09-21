#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51
#define INF 2e9

using namespace std;
int N, M, R, C, D;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
long long answer = 0;

void Operation() {
	while (1) {
		visited[R][C] = true;
		int find = 0;
		while (find < 4) {
			int newD = D - 1;
			if (newD < 0) {
				newD = 3;
			}
			int nextY = R + moveY[newD];
			int nextX = C + moveX[newD];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M)) {
				if (arr[nextY][nextX] == 0) {
					if (!visited[nextY][nextX]) { // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진.
						D = newD;
						R = nextY;
						C = nextX;
						break;
					}
					else { // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 다시 2번부터 진행.
						find++;
						D = newD;
					}
				}
				else if (arr[nextY][nextX] == 1) {
					find++;
					D = newD;
				}
			}
			else {
				find++;
				D = newD;
			}
		};
		if (find == 4) { // 네 방향 모두 청소가 되어있거나 벽인 경우, 뒤쪽 방향이 벽이 아니면 후진. 벽이면 작동 끝.
			int newD = D - 2;
			if (newD < 0) {
				newD += 4;
			}
			int nextY = R + moveY[newD];
			int nextX = C + moveX[newD];
			if (arr[nextY][nextX] == 0) {
				R = nextY;
				C = nextX;
			}
			else if (arr[nextY][nextX] == 1) {
				break;
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> R >> C >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	Operation();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				answer++;
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}