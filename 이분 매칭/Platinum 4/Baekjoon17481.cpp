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
#define MAX 1005
#define INF 1e9+7

using namespace std;
int N, M;
vector<string> Girl_Group;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int Matching = 0;

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

	cin >> N >> M;
	Girl_Group.resize(M + 1);
	for (int i = 1; i <= M; i++) {
		cin >> Girl_Group[i];
	}
	sort(++Girl_Group.begin(), Girl_Group.end());
	for (int i = 1; i <= N; i++) {
		int K;
		cin >> K;
		while (K--) {
			string Name;
			cin >> Name;
			for (int j = 1; j <= M; j++) {
				if (Girl_Group[j] == Name) {
					Graph[i].push_back(j);
					break;
				}
			}
		};
	}
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			Matching++;
		}
	}
	if (Matching != N) {
		cout << "NO" << "\n";
		cout << Matching << "\n";
	}
	else {
		cout << "YES" << "\n";
	}

	getchar();
	getchar();
	return 0;
}