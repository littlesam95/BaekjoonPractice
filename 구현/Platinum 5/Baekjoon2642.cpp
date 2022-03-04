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
#define MAX 7
#define LL long long
#define INF 1e9

using namespace std;
bool answer = true;
int MAP[MAX][MAX];
pair<int, int> Pos[MAX];
int Face[MAX];
bool Path[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

// Depth : Dir�������� �̵��� Ƚ��, Dir : First���� �̵��� ����, (Y, X) : ���� ĭ, First : ó�� DFS�� �������� �� ����(1~6 �� �ϳ�)
void DFS(int Depth, int Dir, int Y, int X, int First) {
	for (int k = 0; k < 4; k++) {
		int nextY = Y + moveY[k];
		int nextX = X + moveX[k];
		int Next = MAP[nextY][nextX];
		if ((nextY >= 1) && (nextY <= 6) && (nextX >= 1) && (nextX <= 6) && (Next > 0) && (!Path[First][Next])) {
			/*
				���� ĭ���� k���⿡ �ִ� ĭ�� 6X6�� ���ڸ� ����� �ʰ�,
				0�� �ƴϸ�(1~6), ���� First���� ������� �� ����ģ ���ڰ� �ƴ� ���
			*/
			Path[First][Next] = true; // First���� ���� ĭ���� ������ ��ην� ǥ���Ѵ�.
			if (Dir == -1) { // ���� k������ ���ʷ� ������ ������ ���
				DFS(1, k, nextY, nextX, First);
			}
			else if ((Dir == k) && (Depth == 1) && ((Face[First] == 0) || (Face[First] == Next)) && ((Face[Next] == 0) || (Face[Next] == First))) {
				/*
					k�������� �̵� ���ε� ���� �̵��� ���� ���� k�����̰�, �̹� k�������� �̵��ϸ鼭 1~6������ ���� �� �ϳ��� ������ ������
					First�� ���� ĭ(Next) ���� ���ֺ��� ���� ���� ������ �ʾ��� ��
				*/
				Face[First] = Next;
				Face[Next] = First;
				DFS(Depth + 1, Dir, nextY, nextX, First);
			}
			else {
				/*
					k�������� �̵� ���ε� ���� �̵��� ������ k���⵵ �ƴ϶��
				*/
				DFS(Depth, Dir, nextY, nextX, First);
			}
		}
	}
}

int main() {
	FIRST
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] > 0) {
				Pos[MAP[i][j]] = make_pair(i, j);
			}
		}
	}
	// 1���� 6������ ���� Ž��
	for (int i = 1; i <= 6; i++) {
		int Y = Pos[i].first;
		int X = Pos[i].second;
		if ((Y == 0) && (X == 0)) { // 1~6�� �Է¹��� ���� ���
			continue;
		}
		Path[i][i] = true;
		DFS(0, -1, Y, X, i); // ���� ����
	}
	for (int i = 1; i <= 6; i++) { // 1~6 �߿� ���ֺ��� ���� ���� ��쿡�� ������ü�� ���� �� ����.
		if (Face[i] == 0) {
			answer = false;
			break;
		}
	}
	if (answer) {
		cout << Face[1] << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	getchar();
	getchar();
	return 0;
}