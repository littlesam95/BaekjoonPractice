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
int V, M, J, S;
int MAP[MAX][MAX];
int Min_Cost = INF;
int Small_Time = INF;
vector<int> Meet_Space;
int answer = -1;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = INF;
		}
	}
}

void Find_Candidate() {
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { // 1. 지헌이의 출발 위치와 성하의 출발 위치는 새로운 약속 장소가 될 수 없다.
			continue;
		}
		if (Min_Cost > MAP[J][i] + MAP[S][i]) {
			// 2. 성품도 훌륭한 지헌이는 새로운 약속 장소는 지헌이가 걸리는 최단 시간과 성하가 걸리는 최단 시간의 합이 최소가 되도록 하고 싶다.
			Min_Cost = MAP[J][i] + MAP[S][i];
		}
	}
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { // 1. 지헌이의 출발 위치와 성하의 출발 위치는 새로운 약속 장소가 될 수 없다.
			continue;
		}
		if ((Min_Cost == MAP[J][i] + MAP[S][i]) && (MAP[J][i] <= MAP[S][i]) && (Small_Time > MAP[J][i])) {
			/* 
				3. 지헌이가 더 늦게 도착하면 성하에게 안좋은 소리를 들을 것이 뻔하기에, 
				1번과 2번 조건을 만족하는 장소 중에서도 지헌이가 성하보다 늦게 도착하는 곳은 약속 장소가 될 수 없다.
				4. 위의 세 조건을 모두 만족하는 약속 장소가 여러 곳이 있다면,
				그 중에 지헌이로부터 가장 가까운 곳이 최종 약속 장소가 된다.
				그런 장소도 여러 곳이 있다면, 그 중에 번호가 가장 작은 장소가 최종 약속 장소가 된다.
			*/
			Small_Time = MAP[J][i];
		}
	}
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) {
			continue;
		}
		if ((Min_Cost == MAP[J][i] + MAP[S][i])  && (Small_Time == MAP[J][i])) {
			Meet_Space.push_back(i);
		}
	}
	if (!Meet_Space.empty()) {
		sort(Meet_Space.begin(), Meet_Space.end());
		answer = Meet_Space[0];
	}
}

int main() {
	FIRST
	init();
	cin >> V >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		MAP[A][B] = min(MAP[A][B], C);
		MAP[B][A] = min(MAP[B][A], C);
	}
	cin >> J >> S;
	// 플로이드-와샬 알고리즘으로 모든 장소 간의 최단 거리를 구한다.
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (MAP[i][j] > MAP[i][k] + MAP[k][j]) {
					MAP[i][j] = MAP[i][k] + MAP[k][j];
				}
			}
		}
	}
	Find_Candidate(); // 조건 4가지에 맞는 후보 장소를 찾는다.
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}