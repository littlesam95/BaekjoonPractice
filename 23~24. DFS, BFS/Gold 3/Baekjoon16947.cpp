#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int x, dist;
};

int N;
bool visited[3001];
bool cycle_station[3001];
vector<int> station[3001];
bool cycle;
vector<int> answer;

void init() {
	for (int i = 0; i < 3001; i++) {
		visited[i] = false;
	}
}

int bfs(int x) {
	queue<Info> q;
	visited[x] = true;
	q.push({ x,0 });

	while (!q.empty()) {
		int now_x = q.front().x;
		int now_dist = q.front().dist;
		q.pop();

		if (cycle_station[now_x]) {
			return now_dist;
		}

		for (int i = 0; i < station[now_x].size(); i++) {
			if (!visited[station[now_x][i]]) {
				visited[station[now_x][i]] = true;
				q.push({ station[now_x][i],now_dist + 1 });
			}
		}
	};

	return -1;
}

void dfs(int point, int start, int line) {
	if ((point == start) && (line >= 2)) {
		cycle = true;
		return;
	}

	visited[point] = true;
	for (int i = 0; i < station[point].size(); i++) {
		if (!visited[station[point][i]]) {
			dfs(station[point][i], start, line + 1);
		}
		else {
			if ((station[point][i] == start) && (line >= 2)) {
				dfs(station[point][i], start, line);
			}
		}
		if (cycle) {
			return;
		}
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		station[n1].push_back(n2);
		station[n2].push_back(n1);
	}
	for (int i = 1; i <= N; i++) {
		init();
		cycle = false;
		int start_station = i;
		dfs(i, start_station, 0);
		if (cycle) {
			cycle_station[i] = true;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (cycle_station[i]) {
			answer.push_back(0);
		}
		else {
			init();
			int line = bfs(i);
			answer.push_back(line);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}