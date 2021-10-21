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
#define MAX 2222
#define INF 1e9+7

using namespace std;
struct SHARK {
	int S, V, I;
};

int N;
vector<SHARK> Shark_vec;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

int Shark_Compare(SHARK A, SHARK B) {
	int cnt = 0;
	if (A.S == B.S) {
		cnt++;
	}
	else if (A.S < B.S) {
		return 0;
	}
	if (A.V == B.V) {
		cnt++;
	}
	else if (A.V < B.V) {
		return 0;
	}
	if (A.I == B.I) {
		cnt++;
	}
	else if (A.I < B.I) {
		return 0;
	}
	if (cnt == 3) {
		return 2;
	}
	return 1;
}

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WORK[Next] == -1) || DFS(WORK[Next])) {
			WORK[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	Shark_vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> Shark_vec[i].S >> Shark_vec[i].V >> Shark_vec[i].I;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int comp = Shark_Compare(Shark_vec[i], Shark_vec[j]);
			if (comp == 0) { // i��° ����� ũ��, �ӵ�, ���� �� �ϳ��� j��° ���� ������ ���� �� ����.
				continue;
			}
			else if (comp == 1) { // i��° ���� j��° ����� ������ �� �۴ٸ� ���� �� �ִ�.
				Graph[i].push_back(j + 50);
			}
			else if (comp == 2) { // i��° ���� j��° ����� ������ �� ���ٸ�
				if (i < j) { // �ռ� ������ �� �� ������ �� �Դ´�.
					Graph[i].push_back(j + 50);
				}
			}
		}
	}
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= N; i++) { // �� ���� �ִ� �� ������ �� ���� �� �����Ƿ� DFS�� �� �� Ž���Ѵ�.
		memset(visited, false, sizeof visited);
		DFS(i);
		memset(visited, false, sizeof visited);
		DFS(i);
	}
	for (int i = 51; i <= 50 + N; i++) { // WORK[i]==-1, �� ��Ƹ����� ����(��Ƴ��� �� �ִ�) ����� ���� ����Ѵ�.
		answer += (WORK[i] == -1);
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}