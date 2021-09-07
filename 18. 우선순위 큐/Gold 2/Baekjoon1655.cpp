#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
priority_queue<int, vector<int>, less<int> > pq1; // 최대힙
priority_queue<int, vector<int>, greater<int> > pq2; // 최소힙

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		// 최대힙의 크기는 항상 최소힙의 크기보다 같거나 1만큼 더 크다. 
		if (pq1.size() > pq2.size()) { // 근데 최대힙이 최소힙의 크기보다 클 때, 최대힙에 원소를 push한다면 최대힙이 최소힙보다 2만큼 커지게 된다.
			pq2.push(X); // 따라서 최소힙에 원소를 push한다.
		}
		else { // 최대힙과 최소힙의 크기가 같다면, 최소힙에 원소를 push하면 최소힙의 크기가 최대힙보다 커지게 된다.
			pq1.push(X); // 따라서 최대힙에 원소를 push한다.
		}
		if ((!pq1.empty()) && (!pq2.empty())) { // 최대힙과 최소힙이 둘 다 비어있지 않다면
			if (pq1.top() > pq2.top()) { // 최소힙의 모든 원소는 최대힙의 모든 원소보다 항상 크거나 같아야 하는데, 최대힙의 top이 최소힙의 top보다 크다면
				// 조건이 만족되지 않는다. 따라서 최대힙의 top과 최소힙의 top을 바꾼다.
				int pq1_top = pq1.top();
				int pq2_top = pq2.top();
				pq1.pop();
				pq2.pop();
				pq2.push(pq1_top);
				pq1.push(pq2_top);
			}
		}
		cout << pq1.top() << "\n"; // 최대힙의 top이 곧 중간값이 될 수 있으므로 최대힙의 top을 출력한다.
	}

	getchar();
	getchar();
	return 0;
}