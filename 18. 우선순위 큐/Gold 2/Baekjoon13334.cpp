#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

// ������ �˰���
using namespace std;
int N, D;
priority_queue<int, vector<int>, greater<int> > pq; // ������ ������� ���� �������� ��� priority queue(�ּ� ������ ����)
vector<pair<int, int> > vec;
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) { // ���� ���� ������������ �����ϵ�, ���� ������ ���ٸ� ��� ������ ������������ �����Ѵ�.
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
	for (int i = 0; i < N; i++) { // ������� �������� �Է¹޴µ�, ����� > �������� ���� swap()�� �̿��Ͽ� �ٲ��ش�.
		int H, O;
		cin >> H >> O;
		if (H > O) {
			swap(H, O);
		}
		vec.push_back(make_pair(H, O));
	}
	cin >> D;
	sort(vec.begin(), vec.end(), comp); // comp() �Լ����� ���� ���Ǵ�� ����
	for (int i = 0; i < vec.size(); i++) {
		if (abs(vec[i].second - vec[i].first) > D) { // ������� ������ ������ �Ÿ��� D���� ũ�ٸ� ���� �� �����Ƿ� continue
			continue;
		}
		while (!pq.empty()) {
			if (abs(vec[i].second - pq.top()) > D) { // ���� ����� �������� priority queue�� ��� �ִ� ���� ���� ������� ���� ����� ��
				// �� ���̰� D�� �Ѵ´ٸ� priority queue�� pop�Ѵ�.
				pq.pop();
			}
			else {
				break;
			}
		};
		pq.push(vec[i].first); // ���� ����� ������� push
		answer = max(answer, (int)pq.size()); // ����� ������� push�� ������ ���� priority queue�� size, �� ���� L�� ���ԵǴ� ������� �ִ��� ���Ѵ�.
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}