#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define INF 1e9

using namespace std;
int N, M, T;
int MAP[MAX][MAX];
bool Will_Erase[MAX][MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Will_Erase[i][j] = false;
		}
	}
}

void Rotation(int X, int D, int K) {
	/*
		원판 회전은 덱의 개념을 도입하여,
		시계 방향으로 회전했을 때는 Back의 K개의 숫자가 pop되어서 다시 덱의 front로 push되고,
		반시계 방향으로 회전했을 때는 front의 K개의 숫자가 pop되어서 다시 덱의 back으로 push되게 하였다.
		물론 덱을 쓰면 복잡해질 것 같아서 덱을 쓰진 않았고 배열을 사용하였다.
	*/
	for (int i = X; i <= N; i += X) {
		if (D == 0) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= (M - K); j++) {
				MAP[i][j + K] = tmp[j];
			}
			for (int j = (M - K + 1); j <= M; j++) {
				MAP[i][j - (M - K)] = tmp[j];
			}
		}
		else if (D == 1) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= K; j++) {
				MAP[i][j + (M - K)] = tmp[j];
			}
			for (int j = K + 1; j <= M; j++) {
				MAP[i][j - K] = tmp[j];
			}
		}
	}
}

void Erase_Number() {
	init();
	bool Same_Number = false; // 같은 숫자가 있어 숫자가 지워졌다면 true로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}
			int Left = j - 1;
			int Right = j + 1;
			int Top = i + 1;
			int Bottom = i - 1;
			if (Left == 0) { // j가 1이라면 왼쪽의 숫자는 M번째 숫자가 될 것이다.
				Left = M;
			}
			if (Right == M + 1) { // j가 M이라면 오른쪽의 숫자는 1번째 숫자가 될 것이다.
				Right = 1;
			}
			bool Flag = false; // 같은 숫자가 하나라도 존재한다면 true로 초기화
			if (MAP[i][j] == MAP[i][Left]) {
				Flag = true;
				Will_Erase[i][Left] = true; // 지울 숫자를 마킹
			}
			if (MAP[i][j] == MAP[i][Right]) {
				Flag = true;
				Will_Erase[i][Right] = true;
			}
			if (MAP[i][j] == MAP[Top][j]) {
				if (i < N) {
					Flag = true;
					Will_Erase[Top][j] = true;
				}
			}
			if (MAP[i][j] == MAP[Bottom][j]) {
				if (i > 1) {
					Flag = true;
					Will_Erase[Bottom][j] = true;
				}
			}
			if (Flag) {
				Will_Erase[i][j] = true;
				Same_Number = true;
			}
		}
	}
	if (Same_Number) {
		// 같은 숫자가 존재한다면 마킹한 숫자들을 지운다.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (Will_Erase[i][j]) {
					MAP[i][j] = 0;
				}
			}
		}
	}
	else { // 같은 숫자가 존재하지 않는다면
		int sum = 0;
		int size = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					sum += MAP[i][j];
					size++;
				}
			}
		}
		// 평균을 구한다. 이 평균보다 높은 숫자는 -1, 낮은 숫자는 +1한다.
		double avg = (double)sum / (double)size;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					if (avg > (double)MAP[i][j]) {
						MAP[i][j]++;
					}
					else if (avg < (double)MAP[i][j]) {
						MAP[i][j]--;
					}
				}
			}
		}
	}
}

int Calc_Sum() {
	// 원판에 남아 있는 모든 숫자들을 더한다.
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += MAP[i][j];
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N >> M >> T;
	// 원판의 처음 상태 설정
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int X, D, K;
		cin >> X >> D >> K;
		// 원판 회전
		Rotation(X, D, K);
		// 지울 수 있는 숫자 지우기
		Erase_Number();
	}
	cout << Calc_Sum() << "\n"; // 남아 있는 숫자들의 합

	getchar();
	getchar();
	return 0;
}