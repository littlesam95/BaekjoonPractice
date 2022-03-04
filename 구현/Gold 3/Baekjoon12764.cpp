#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define INF 1e9

using namespace std;
int N;
pair<int, int> User[MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
set<int> Seat; // 현재 좌석의 상태, 자동 정렬됨(BS Tree와 같은 자료구조)
int answer;
int Computer[MAX];

int Arrange() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		while (!pq.empty()) {
			if (pq.top().first <= User[i].first) {
				// i번째 사람의 시작 시간보다 시작 시간이 빠른 사람들 pop
				Seat.insert(pq.top().second); // 싸지방 좌석에 앉힌다.
				pq.pop();
			}
			else break;
		};
		if (Seat.empty()) { // 남는 자리가 없으므로, 다음 번호의 컴퓨터를 부여
			pq.push(make_pair(User[i].second, res));
			Computer[res++]++;
		}
		else { // set의 첫 번째 원소가 제일 일찍 끝난 사람이므로, i번째 사람을 첫 번째 자리에 앉힌다.
			pq.push(make_pair(User[i].second, *Seat.begin()));
			Computer[*Seat.begin()]++;
			Seat.erase(Seat.begin());
		}
	}
	return res;
}

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.first < B.first);
}

int main() {
	FIRST
		cin >> N;
	for (int i = 0; i < N; i++) {
		int P, Q;
		cin >> P >> Q;
		User[i] = make_pair(P, Q);
	}
	// 사람들의 싸지방 이용 정보를 시작 시간을 기준으로 정렬한다.
	sort(User, User + N, comp);
	answer = Arrange();
	cout << answer << "\n";
	for (int i = 0; i < answer; i++) {
		cout << Computer[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}