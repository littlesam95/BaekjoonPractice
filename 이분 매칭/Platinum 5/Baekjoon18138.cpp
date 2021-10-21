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
#define MAX 202
#define INF 1e9+7

using namespace std;
int N, M;
double ShirtW[MAX];
double KaraW[MAX];
int WANT[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

bool DFS(int X) {
	for (int i = 0; i < Graph[X].size(); i++) {
		int Next = Graph[X][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WANT[Next] == 0) || DFS(WANT[Next])) {
			WANT[Next] = X;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> ShirtW[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> KaraW[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (((KaraW[j] >= ShirtW[i] * 0.5) && (KaraW[j] <= ShirtW[i] * 0.75)) || ((KaraW[j] >= ShirtW[i]) && (KaraW[j] <= ShirtW[i] * 1.25))) {
				Graph[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
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