#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 1000000007

using namespace std;
int N, M;
long long dist[501];
vector<pair<pair<int, int>, int> > vec;

void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = MAX;
	}
}

void bellman_ford() {
	dist[1] = 0; // 1번 도시에서 출발하기 때문에 1번 정점의 비용을 0이라고 한다.
	for (int i = 1; i <= N - 1; i++) { // 
		for (int j = 0; j < vec.size(); j++) {
			int S = vec[j].first.first;
			int E = vec[j].first.second;
			int now_cost = vec[j].second;
			if (dist[S] == MAX) { // 출발 정점이 계산되지 않은 정점이라면 패스
				continue;
			}
			if (dist[E] > dist[S] + now_cost) { // 출발 정점이 계산된 정점이라면 해당 간선이 잇는 정점의 거리를 비교해서 최신화
				dist[E] = dist[S] + now_cost;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int S = vec[i].first.first;
		int E = vec[i].first.second;
		int now_cost = vec[i].second;
		if (dist[S] == MAX) {
			continue;
		}
		if (dist[E] > dist[S] + now_cost) {
			// 정상적인 그래프라면(음의 사이클이 발생하지 않는 그래프라면) N - 1번을 탐색한 이후 또 한번의 탐색을 더 하더라도 최소 비용이 변하게 되는 정점이 발생하지 않을 것이다.
			// 따라서 최소 비용이 변하게 되는 장점이 N번째 탐색에서 존재한다면 그것은 음의 사이클이 발생하는 그래프가 된다.
			// 이것은 문제에서 "시간을 무한히 오래 전으로 되돌릴 수 있다면" 이라는 구절에 해당한다. 따라서 음의 사이클이 발생하는 그래프라면 -1을 출력하고 종료한다.
			cout << -1 << "\n";
			return;
		}
	}
	for (int i = 2; i <= N; i++) { // 정상적인 그래프라면 1번 도시에서 2~N번 도시까지 이동하는 과정에서의 최소 비용을 출력한다.
		if (dist[i] == MAX) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back(make_pair(make_pair(a, b), c));
	}
	bellman_ford();

	getchar();
	getchar();
	return 0;
}