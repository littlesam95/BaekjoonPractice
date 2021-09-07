#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

// 스위핑 알고리즘
using namespace std;
int N, D;
priority_queue<int, vector<int>, greater<int> > pq; // 가능한 사람들의 왼쪽 시작점을 담는 priority queue(최소 힙으로 동작)
vector<pair<int, int> > vec;
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) { // 도착 지점 오름차순으로 정렬하되, 도착 지점이 같다면 출발 지점의 오름차순으로 정렬한다.
	if (A.second == B.second) {
		return (A.first < B.first);
	}
	return (A.second < B.second);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) { // 출발지와 도착지를 입력받는데, 출발지 > 도착지인 경우는 swap()을 이용하여 바꿔준다.
		int H, O;
		cin >> H >> O;
		if (H > O) {
			swap(H, O);
		}
		vec.push_back(make_pair(H, O));
	}
	cin >> D;
	sort(vec.begin(), vec.end(), comp); // comp() 함수에서 세운 조건대로 정렬
	for (int i = 0; i < vec.size(); i++) {
		if (abs(vec[i].second - vec[i].first) > D) { // 출발지와 도착지 사이의 거리가 D보다 크다면 담을 수 없으므로 continue
			continue;
		}
		while (!pq.empty()) {
			if (abs(vec[i].second - pq.top()) > D) { // 현재 사람의 도착지를 priority queue에 담겨 있는 가장 앞의 출발지를 가진 사람과 비교
				// 그 차이가 D를 넘는다면 priority queue를 pop한다.
				pq.pop();
			}
			else {
				break;
			}
		};
		pq.push(vec[i].first); // 현재 사람의 출발지를 push
		answer = max(answer, (int)pq.size()); // 사람의 출발지를 push할 때마다 현재 priority queue의 size, 즉 선분 L에 포함되는 사람들의 최댓값을 구한다.
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}