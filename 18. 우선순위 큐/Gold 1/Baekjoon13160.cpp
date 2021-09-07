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
struct Info {
	int S, E, idx;
};

struct comp1 {
	bool operator()(Info &A, Info &B) {
		return (A.E > B.E);
	}
};

int N;
Info tmp;
priority_queue<Info, vector<Info>, comp1> pq;
vector<Info> vec;
int answer = 0;
vector<Info> answer_vec;

bool comp(Info A, Info B) { // 시작점 기준으로 오름차순, 시작점이 같으면 끝점을 기준으로 오름차순
	if (A.S == B.S) {
		return (A.E < B.E);
	}
	return (A.S < B.S);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int S, E;
		cin >> S >> E;
		tmp.S = S;
		tmp.E = E;
		tmp.idx = i;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), comp);
	for (int i = 0; i < vec.size(); i++) {
		while (!pq.empty()) {
			if (pq.top().E < vec[i].S) {
				pq.pop();
			}
			else {
				break;
			}
		};
		pq.push(vec[i]);
		answer = max(answer, (int)pq.size());
	}
	cout << answer << "\n";
	while (!pq.empty()) {
		pq.pop();
	};
	for (int i = 0; i < vec.size(); i++) {
		while (!pq.empty()) {
			if (pq.top().E < vec[i].S) {
				pq.pop();
			}
			else {
				break;
			}
		};
		pq.push(vec[i]);
		if (pq.size() == answer) {
			while (!pq.empty()) {
				cout << pq.top().idx << " ";
				pq.pop();
			};
			break;
		}
	}

	getchar();
	getchar();
	return 0;
}