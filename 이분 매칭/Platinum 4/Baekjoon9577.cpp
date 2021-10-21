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
#define MAX 101
#define INF 1e9+7

using namespace std;
int T, N, M, Last_Time, Download_size;
pair<double, double> MOUSE[MAX];
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer;

void init() {
	answer = -1;
	Last_Time = 0;
	Download_size = 0;
	for (int i = 0; i < MAX; i++) {
		Graph[i].clear();
	}
	memset(WORK, -1, sizeof WORK);
}

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (!visited[Next]) {
			visited[Next] = true;
			if ((WORK[Next] == -1) || DFS(WORK[Next])) {
				WORK[Next] = E;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			int T1, T2, A;
			cin >> T1 >> T2 >> A;
			Last_Time = max(Last_Time, T2);
			while (A--) {
				int Q;
				cin >> Q;
				for (int j = T1; j < T2; j++) {
					Graph[j].push_back(Q);
				}
			};
		}
		for (int i = 0; i < Last_Time; i++) {
			sort(Graph[i].begin(), Graph[i].end());
			Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());
		}
		for (int i = 0; i < Last_Time; i++) {
			memset(visited, false, sizeof visited);
			if (DFS(i)) {
				Download_size++;
			}
			if (Download_size == N) {
				answer = i + 1;
				break;
			}
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}