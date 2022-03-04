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
int N;
int Order[10];
int Baseball[MAX][10];
bool visited[10];
int answer = 0;

int Play_Baseball() {
	int score = 0;
	int startP = 1;
	bool Base_State[4]; // 0�� Ȩ, 1�� 1��, 2�� 2��, 3�� 3��, true�� X�翡 ����� �ִٴ� �ǹ�, false�� X�翡 ����� ���ٴ� �ǹ��̴�.
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			Base_State[j] = false;
		}
		int OutCount = 0;
		bool isNextIning = false;
		while (1) { // �� �ݺ����� break�ȴٸ� i��° �̴��� ���� ���̴�.
			for (int j = startP; j <= 9; j++) {
				if (Baseball[i][Order[j]] == 0) { // �ƿ�
					OutCount++;
				}
				else if (Baseball[i][Order[j]] == 1) { // ��Ÿ
					for (int k = 3; k >= 1; k--) {
						if (Base_State[k]) {
							if (k == 3) {
								Base_State[k] = false;
								score++;
							}
							else {
								Base_State[k + 1] = true;
								Base_State[k] = false;
							}
						}
					}
					Base_State[1] = true;
				}
				else if (Baseball[i][Order[j]] == 2) { // 2��Ÿ
					for (int k = 3; k >= 1; k--) {
						if (Base_State[k]) {
							if (k >= 2) {
								Base_State[k] = false;
								score++;
							}
							else if (k == 1) {
								Base_State[k + 2] = true;
								Base_State[k] = false;
							}
						}
					}
					Base_State[2] = true;
				}
				else if (Baseball[i][Order[j]] == 3) { // 3��Ÿ
					for (int k = 3; k >= 1; k--) {
						if (Base_State[k]) {
							Base_State[k] = false;
							score++;
						}
					}
					Base_State[3] = true;
				}
				else if (Baseball[i][Order[j]] == 4) { // Ȩ��
					for (int k = 3; k >= 1; k--) {
						if (Base_State[k]) {
							Base_State[k] = false;
							score++;
						}
					}
					score++;
				}

				if (OutCount == 3) { // 3�ƿ��� �߻��ߴٸ� �̴��� ����
					startP = j + 1;
					if (startP > 9) {
						startP = 1;
					}
					isNextIning = true;
					break;
				}
			}
			if (isNextIning) {
				break;
			}
			else {
				startP = 1;
			}
		};
	}

	return score;
}

void DFS(int depth) {
	if (depth == 10) {
		int score = Play_Baseball();
		answer = max(answer, score);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			Order[i] = depth;
			DFS(depth + 1);
			Order[i] = 0;
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> Baseball[i][j];
		}
	}
	visited[4] = true;
	Order[4] = 1;
	DFS(2);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}