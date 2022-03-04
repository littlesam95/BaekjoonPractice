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
#define MAX 105
#define LL long long
#define INF 1e9

using namespace std;
int N, L;
int MAP1[MAX][MAX];
int MAP2[MAX][MAX];

bool Make_Road_Able(int MAP[][MAX], int Y, int X) {
	int Height = MAP[Y][X]; // 높이가 1 낮아진 다음 땅
	for (int i = X; i < (X + L); i++) { // L개의 다음 땅의 높이는 전부 같아야 함.
		if (MAP[Y][i] != Height) {
			return false; // 하나라도 다르다면 경사로를 세울 수 없다.
		}
	}
	return true;
}

int Make_Road(int MAP[][MAX]) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		bool Can_Make_Road = true;
		int Chain_Road = 1; // 현재까지 연결된 땅의 길이
		for (int j = 0; j < (N - 1); j++) {
			if (MAP[i][j] == MAP[i][j + 1]) { // 현재 땅과 다음 땅의 높이가 같은 경우
				Chain_Road++; // 바로 연결시켜 준다.
			}
			else if (MAP[i][j] == (MAP[i][j + 1] + 1)) { // 다음 땅의 높이가 더 높은 경우
				if (Make_Road_Able(MAP, i, j + 1)) {
					j += (L - 1); // 다음 L개의 땅은 확인했으니 건너뛴다.
					Chain_Road = 0;
				}
				else {
					Can_Make_Road = false;
					break;
				}
			}
			else if (MAP[i][j] == (MAP[i][j + 1] - 1)) { // 현재 땅의 높이가 더 높은 경우
				if (Chain_Road >= L) { // 현재까지 연결된 땅의 길이가 L 이상이어야 경사로를 놓을 수 있다.
					Chain_Road = 1; // 경사로를 놓았다면 다시 MAP[i][j+1]부터 높이를 확인하며, 연결된 땅의 길이는 다시 1이 된다.
				}
				else {
					Can_Make_Road = false;
					break;
				}
			}
			else if (abs(MAP[i][j] - MAP[i][j + 1]) >= 2) { // 현재 땅과 다음 땅의 높이 차이가 2 이상인 경우
				Can_Make_Road = false; // 높이 차이가 2 이상인 경우 경사로를 놓을 수 없다.
				break;
			}
		}
		if (Can_Make_Road) {
			res++;
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP1[i][j]; // 행 기준으로 확인하기 위한 배열 MAP1
			MAP2[j][i] = MAP1[i][j]; // 열 기준으로 확인하기 위한 배열 MAP2
		}
	}

	cout << Make_Road(MAP1) + Make_Road(MAP2) << "\n";

	getchar();
	getchar();
	return 0;
}