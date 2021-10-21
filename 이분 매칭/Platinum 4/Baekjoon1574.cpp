#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 301
#define INF 1e9+7

using namespace std;
int R, C, N;
int WORK_R[MAX], WORK_C[MAX];
bool visited[MAX], isBlock[MAX][MAX];
vector<int> Graph[MAX];
int answer = 0;

bool DFS(int E) {
	visited[E] = true;
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if ((WORK_C[Next] == -1) || (!visited[WORK_C[Next]] && DFS(WORK_C[Next]))) {
			WORK_R[E] = Next;
			WORK_C[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> N;
	for (int i = 1; i <= N; i++) { // (Y, X) ��ǥ�� ���� ���´�.
		int Y, X;
		cin >> Y >> X;
		isBlock[Y][X] = true;
	}
	for (int i = 1; i <= R; i++) { // ���� ��������, i�� j���� ���� ���� ���� ������ i��� j���� ��Ī�Ѵ�.
		for (int j = 1; j <= C; j++) {
			if (!isBlock[i][j]) {
				Graph[i].push_back(j);
			}
		}
	}
	memset(WORK_R, -1, sizeof WORK_R);
	memset(WORK_C, -1, sizeof WORK_C);
	for (int i = 1; i <= R; i++) {
		if (WORK_R[i] != -1) { // i��� ��Ī�� j���� ���ٸ� DFS�� �����Ѵ�.
			continue;
		}
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}